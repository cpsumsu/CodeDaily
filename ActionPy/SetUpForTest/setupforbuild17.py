import re
import pytest
import os

CPP11 = 'g++ -std=c++11 -o'
CPP14 = 'g++ -std=c++14 -o'
CPP17 = 'g++ -std=c++17 -o'
CPP11PY = 'test_cpp_11_build.py'
CPP14PY = 'test_cpp_14_build.py'
CPP17PY = 'test_cpp_17_build.py'

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


with open(f"ActionPy/{CPP17PY}", "w+", encoding='utf-8') as file:
    file.write(f"# {CPP17PY}.py\n")
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
                    
                    # TODO: ADD more test function
                    t.write("\n")
                    t.write("int main()\n")
                    t.write("{\n")
                    t.write("   return 0;\n")
                    t.write("}")


                file.write(f'@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/{function_name}.cpp", "{CPP17} ActionPy/TempCppGen/cpp17/{function_name}Gen ActionPy/TempCppGen/{function_name}.cpp")])\n')
                file.write(f"def test_build_cpp_{function_name}(test_case):\n")
                file.write('    cpp_file, build_command = test_case\n')
                file.write("    try:\n")
                file.write("        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)\n")
                file.write("    except subprocess.CalledProcessError as e:\n")
                file.write("        pytest.fail(f\"Failed to build C++ code: {e}\")\n")
                file.write("\n")
    # file.write("# 在其他地方調用測試函數\n")
    # file.write("test_build_cpp(\"solution.cpp\", \"g++ -std=c++11 -o solution\")\n")