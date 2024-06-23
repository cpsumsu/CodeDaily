# test_cpp_20_build.py
import subprocess
import pytest
import os
from pathlib import Path

def fetch_md():
    "all the markdown files name in the leetcode folder"
    test_path = 'leetcode'
    markdown_files = [Path(test_path) / f for f in os.listdir(test_path) if f.endswith('.md')]
    markdown_files = [str(file).split('.')[0] for file in markdown_files]
    return markdown_files

def pytest_generate_tests(metafunc):  
    "generate test cases for the build_cpp20 function"
    
    if 'build_command' in metafunc.fixturenames:    
        file_paths = [Path('AciotnPy/TempCppGen/cpp20') / file for file in fetch_md()]
        build_commands = [f"g++ -std=c++20 -o {file_path}Gen {file_path}.cpp" for file_path in file_paths]
        print(build_commands)
        metafunc.parametrize('build_command', build_commands)
        
def test_build_cpp20_anton(build_command):
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")
