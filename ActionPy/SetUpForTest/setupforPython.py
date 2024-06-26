import os
import PythonBuildHeader

Pythonrun = 'python'
PythonPY = 'test_python_build.py'
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
                if "class Solution:" in "\n".join(current_block):
                    modified_block = []
                    for elem in current_block:
                        if " * Definition for a binary tree node." in elem:
                            data_structure.add("binary tree node")
                        elif " * Definition for singly-linked list." in elem:
                            data_structure.add("singly-linked list")
                        if "class Solution:" in elem:
                            modified_block.append(f"\n\nclass Solution_{chr(solution_count + 97)}:")
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
            code_blocks.insert(0, PythonBuildHeader.BINARY_TREE)
        elif (d == "Node"):
            code_blocks.insert(0, PythonBuildHeader.NODE)
        elif (d == "singly-linked list"):
            code_blocks.insert(0, PythonBuildHeader.SINGLE_LINKED_LIST)
    
    return code_blocks


with open(f"ActionPy/{PythonPY}", "w+", encoding='utf-8') as file:
    file.write(f"# {PythonPY}.py\n")
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

            if len(res) >= 1:
                # ccode = res.group('ccode')
                with open(f"ActionPy/TempPyGen/{function_name}.py", 'w+', encoding='utf-8') as t:
                    t.write(PythonBuildHeader.LEETCODE_HEADER)
                    t.write(''.join([str(elem) for i,elem in enumerate(res)]))
                    
                    # TODO: ADD more test function
                    # (?<return_type>[\w<\&>]+) (?<function_name>\w+)\((?<param_type>\w+)<(?<param_type_arg>\w+)>& (?<param_name>\w+)\)
                    
                file.write(f'@pytest.mark.parametrize("test_case", [("ActionPy/TempPyGen/{function_name}.py", "{Pythonrun} ActionPy/TempPyGen/{function_name}.py")])\n')
                file.write(f"def test_build_python_{function_name}(test_case):\n")
                file.write('    python_file, build_command = test_case\n')
                file.write("    try:\n")
                file.write("        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)\n")
                file.write("    except subprocess.CalledProcessError as e:\n")
                file.write("        pytest.fail(f\"Failed to build Python code: {e}\")\n")
                # file.write("        pass\n")
                file.write("\n")