# test_python_build.py.py
import subprocess
import pytest

@pytest.mark.parametrize("test_case", [("ActionPy/TempPyGen/1239.py", "python ActionPy/TempPyGen/1239.py")])
def test_build_python_1239(test_case):
    python_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build Python code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempPyGen/1410.py", "python ActionPy/TempPyGen/1410.py")])
def test_build_python_1410(test_case):
    python_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build Python code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempPyGen/2696.py", "python ActionPy/TempPyGen/2696.py")])
def test_build_python_2696(test_case):
    python_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build Python code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempPyGen/2786.py", "python ActionPy/TempPyGen/2786.py")])
def test_build_python_2786(test_case):
    python_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build Python code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempPyGen/2824.py", "python ActionPy/TempPyGen/2824.py")])
def test_build_python_2824(test_case):
    python_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build Python code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempPyGen/32.py", "python ActionPy/TempPyGen/32.py")])
def test_build_python_32(test_case):
    python_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build Python code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempPyGen/526.py", "python ActionPy/TempPyGen/526.py")])
def test_build_python_526(test_case):
    python_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build Python code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempPyGen/62.py", "python ActionPy/TempPyGen/62.py")])
def test_build_python_62(test_case):
    python_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build Python code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempPyGen/689.py", "python ActionPy/TempPyGen/689.py")])
def test_build_python_689(test_case):
    python_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build Python code: {e}")

