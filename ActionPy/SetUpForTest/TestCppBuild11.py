import re
import subprocess
import pytest

def test_build_cpp(cpp_file, build_command):
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")
