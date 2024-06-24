import os
import CppBuildHeader

CPP20 = 'g++ -std=c++20 -o'
CPP20PY = 'test_cpp_20_build.py'
SEP_FUNCTION_MODE = True

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
    data_structure = set()
    
    for line in markdown_text.split("\n"):
        if line.startswith("```"):
            if in_code_block:
                if "class Solution {" in "\n".join(current_block):
                    modified_block = []
                    for elem in current_block:
                        if " * Definition for a binary tree node." in elem:
                            data_structure.add("binary tree node")
                        elif "// Definition for a Node." in elem:
                            data_structure.add("Node")
                        elif " * Definition for singly-linked list." in elem:
                            data_structure.add("singly-linked list")
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
    
    for d in data_structure:
        if (d == "binary tree node"):
            code_blocks.insert(0, CppBuildHeader.BINARY_TREE)
        elif (d == "Node"):
            code_blocks.insert(0, CppBuildHeader.NODE)
        elif (d == "singly-linked list"):
            code_blocks.insert(0, CppBuildHeader.SINGLE_LINKED_LIST)
    
    return code_blocks


with open(f"ActionPy/{CPP20PY}", "w+", encoding='utf-8') as file:
    file.write(f"# {CPP20PY}.py\n")
    file.write("import subprocess\n")
    file.write("import pytest\n")
    file.write("\n")
    
    markdown_files = [os.path.join('leetcode/', f) for f in os.listdir('leetcode') if f.endswith('.md')]
    if SEP_FUNCTION_MODE:
        for i, file_path in enumerate(markdown_files):
            file_name = os.path.splitext(os.path.basename(file_path))[0]
            function_name = f'{file_name.split(". ")[0]}'
            with open(f'{file_path}', 'r', encoding='utf-8') as mdfs:
                c = mdfs.read()
                
                res = extract_code_blocks(c)

                if res is not None:
                    # ccode = res.group('ccode')
                    with open(f"ActionPy/TempCppGen/{function_name}.cpp", 'w+', encoding='utf-8') as t:
                        t.write(CppBuildHeader.LEETCODE_HEADER)
                        t.write(''.join([str(elem) for i,elem in enumerate(res)]))
                        
                        # TODO: ADD more test function
                        # (?<return_type>[\w<\&>]+) (?<function_name>\w+)\((?<param_type>\w+)<(?<param_type_arg>\w+)>& (?<param_name>\w+)\)
                        t.write("\n")
                        t.write("int main()\n")
                        t.write("{\n")
                        t.write("   return 0;\n")
                        t.write("}")

                file.write(f'@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/{function_name}.cpp", "{CPP20} ActionPy/TempCppGen/cpp20/{function_name}Gen ActionPy/TempCppGen/{function_name}.cpp")])\n')
                file.write(f"def test_build_cpp_{function_name}(test_case):\n")
                file.write('    cpp_file, build_command = test_case\n')
                file.write("    try:\n")
                file.write("        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)\n")
                file.write("    except subprocess.CalledProcessError as e:\n")
                file.write("        pytest.fail(f\"Failed to build C++ code: {e}\")\n")
                # file.write("        pass\n")
                file.write("\n")
    else:
        file_paths = []
        for i, file_path in enumerate(markdown_files):
            file_name = os.path.splitext(os.path.basename(file_path))[0]
            function_name = f'{file_name.split(". ")[0]}'
            with open(f'{file_path}', 'r', encoding='utf-8') as mdfs:
                c = mdfs.read()
                
                res = extract_code_blocks(c)

                if res is not None:
                    # ccode = res.group('ccode')
                    with open(f"ActionPy/TempCppGen/{function_name}.cpp", 'w+', encoding='utf-8') as t:
                        t.write(CppBuildHeader.LEETCODE_HEADER)
                        t.write(''.join([str(elem) for i,elem in enumerate(res)]))
                        
                        # TODO: ADD more test function
                        # (?<return_type>[\w<\&>]+) (?<function_name>\w+)\((?<param_type>\w+)<(?<param_type_arg>\w+)>& (?<param_name>\w+)\)
                        t.write("\n")
                        t.write("int main()\n")
                        t.write("{\n")
                        t.write("   return 0;\n")
                        t.write("}")
                    file_paths.append(function_name)
                

        file.write(f'@pytest.mark.parametrize("test_case", [\n')
        for p in file_paths:
            file.write(f'("ActionPy/TempCppGen/{p}.cpp", "{CPP20} ActionPy/TempCppGen/cpp20/{p}Gen ActionPy/TempCppGen/{p}.cpp")')
            if p != file_paths[-1]:
                file.write(',\n')

        file.write(f'])\n')

        file.write(f"def test_build_cpp20_build(test_case):\n")
        file.write('    cpp_file, build_command = test_case\n')
        file.write("    try:\n")
        file.write("        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)\n")
        file.write("    except subprocess.CalledProcessError as e:\n")
        file.write("        pytest.fail(f\"Failed to build C++ code: {e}\")\n")
                # file.write("        pass\n")
        file.write("\n")
    # file.write("# 在其他地方調用測試函數\n")
    # file.write("test_build_cpp(\"solution.cpp\", \"g++ -std=c++11 -o solution\")\n")