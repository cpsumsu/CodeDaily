import re
import pytest
import os

CPP11 = '\"g++ -std=c++11 -o solution\"'
CPP20 = '\"g++ -std=c++20 -o solution\"'
CPP08 = '\"g++ -std=c++08 -o solution\"'

def extract_code_blocks(markdown_text):
    """
    Extracts code blocks containing 'class Solution' from a Markdown text.
    
    Args:
        markdown_text (str): The Markdown text to extract code blocks from.
    
    Returns:
        list: A list of code blocks, where each code block is a string.
    """
    code_blocks = []
    current_block = []
    in_code_block = False
    solution_count = 0
    
    for line in markdown_text.split("\n"):
        if line.startswith("```"):
            if in_code_block:
                if "class Solution {" in "\n".join(current_block):
                    modified_block = []
                    for elem in current_block:
                        if "class Solution {" in elem:
                            modified_block.append(f"\n\nclass Solution_{chr(solution_count + 97)} {{")
                            solution_count += 1
                        else:
                            modified_block.append(elem)
                    code_blocks.append("\n".join(modified_block))
                current_block = []
            else:
                in_code_block = True
                solution_count = 0
        elif in_code_block:
            current_block.append(line)
    
    if current_block and "class Solution {" in "\n".join(current_block):
        modified_block = []
        for elem in current_block:
            if "class Solution {" in elem:
                modified_block.append(f"\n\nclass Solution_{chr(solution_count + 97)} {{")
                solution_count += 1
            else:
                modified_block.append(elem)
        code_blocks.append("\n".join(modified_block))
    
    return code_blocks
cb = extract_code_blocks(
"""
---
Difficulty: "Medium"
tags: ["String", "dp","Manacher"]
---

> Problem: [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
# Method 1 (dp)
## Analysis 
- **first observe the pattern:**
    - string size = 1, the output must be the string itself.
    - for string size = 2, if the 2 characters are the same, then it is a palindrome.
- for a generalized pattern, as we loop through the palindromes, we see that:
> if `aba` is a palindrome then `xabax` will also be a palindrome.
- so it is obvious that substrings are related by their length or more specifically, **index**.
- let `dp[j][i]` represent whether if the substring(j,i)(*here means from the index j to i*) is a palindrome or not.
- the core coding is as follows:
```cpp
if(s[i] == s[j] && (L<3 || dp[j+1][i-1])){
    dp[j][i] = true;
}
```

## Code
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<2) return s;

        int pos=0,len=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        for(int i=0; i<n;i++){
            dp[i][i] = true;
            for(int j=0;j<=i;j++){
                int L = i-j+1;
                if(s[i] == s[j] && (L<3 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    if (L >= len){
                        len=L;
                        pos=j;
                    }
                }
            }
        }
        return s.substr(pos,len);
    }
};
```	
## Complexity
### Time
>$O(n^2)$
### Space
>$O(n*2)$

 *** 

 # Method 2 (expand from centre)
## Analysis 
- this method is even easier.
- we can observe that palindromes have same elements at their head and tails. 
- so all we have to do is to enumerate every element as a centre of the possible palindrome substring.
- be noted that we need to seperate dealing odd centres and even centres.

## Code
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        //initialisation
        int start=0;
        int length=1;
        int n=s.length();

        //loop through the even and odd centres
        for(int i=0;i<n;i++){
            //even 
            int lower = i;
            int upper = i+1;
            while((upper < n && lower >=0) && s[lower]==s[upper]){
                if((upper-lower+1) >= length) length = upper-lower+1,start=lower ;
                lower--;
                upper++;
            }

            //odd
            lower = i-1;
            upper = i+1;
            while((upper < n && lower >=0) && s[lower]==s[upper]){
                if((upper-lower+1) >= length) length = upper-lower+1,start=lower ;
                lower--;
                upper++;
            }
        }
        return s.substr(start,length);
    }
    
};
```	
## Complexity
### Time
>$O(n^2)$
### Space
>$O(1)$

# Method 3 (Manachers)
"""
)

with open("ActionPy/test_cpp_11_build.py", "w+", encoding='utf-8') as file:
    file.write("# test_cpp_11_build.py\n")
    file.write("import subprocess\n")
    file.write("import pytest\n")
    file.write("\n")
    
    markdown_files = [os.path.join('leetcode/', f) for f in os.listdir('leetcode') if f.endswith('.md')]

    for i, file_path in enumerate(markdown_files):
        file_name = os.path.splitext(os.path.basename(file_path))[0]
        function_name = f'{file_name.split(". ")[0]}'
        with open(f'{file_path}', 'r', encoding='utf-8') as mdfs:
            c = mdfs.read()
            
            res = extract_code_blocks(c)

            if res is not None:
                # ccode = res.group('ccode')
                with open(f"ActionPy/TempCppGen/{function_name}.cpp", 'w+', encoding='utf-8') as t:
                    t.write("#include <iostream>\n")
                    t.write("#include <vector>\n")
                    t.write("#include <algorithm>\n")
                    t.write('#include <string>\n')
                    t.write('#include <unordered_map>\n')
                    t.write("using namespace std;\n")
                    t.write(''.join([str(elem) for i,elem in enumerate(res)]))

                file.write(f'@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/{function_name}.cpp", {CPP11})])\n')
                file.write(f"def test_build_cpp_{function_name}(test_case):\n")
                file.write('    cpp_file, build_command = test_case\n')
                file.write("    try:\n")
                file.write("        subprocess.check_call(build_command.split(), cwd=cpp_file, stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)\n")
                file.write("    except subprocess.CalledProcessError as e:\n")
                file.write("        pytest.fail(f\"Failed to build C++ code: {e}\")\n")
                file.write("\n")
    # file.write("# 在其他地方調用測試函數\n")
    # file.write("test_build_cpp(\"solution.cpp\", \"g++ -std=c++11 -o solution\")\n")