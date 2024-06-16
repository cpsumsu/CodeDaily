# test_cpp_17_build.py
import subprocess
import pytest

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/100121.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/100121Gen ActionPy/TempCppGen/100121.cpp")])
def test_build_cpp_100121(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/100133.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/100133Gen ActionPy/TempCppGen/100133.cpp")])
def test_build_cpp_100133(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/100138.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/100138Gen ActionPy/TempCppGen/100138.cpp")])
def test_build_cpp_100138(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/100242.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/100242Gen ActionPy/TempCppGen/100242.cpp")])
def test_build_cpp_100242(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/100264.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/100264Gen ActionPy/TempCppGen/100264.cpp")])
def test_build_cpp_100264(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1004.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1004Gen ActionPy/TempCppGen/1004.cpp")])
def test_build_cpp_1004(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1019.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1019Gen ActionPy/TempCppGen/1019.cpp")])
def test_build_cpp_1019(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1026.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1026Gen ActionPy/TempCppGen/1026.cpp")])
def test_build_cpp_1026(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1038.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1038Gen ActionPy/TempCppGen/1038.cpp")])
def test_build_cpp_1038(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/105.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/105Gen ActionPy/TempCppGen/105.cpp")])
def test_build_cpp_105(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1068.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1068Gen ActionPy/TempCppGen/1068.cpp")])
def test_build_cpp_1068(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1094.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1094Gen ActionPy/TempCppGen/1094.cpp")])
def test_build_cpp_1094(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/11.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/11Gen ActionPy/TempCppGen/11.cpp")])
def test_build_cpp_11(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1146.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1146Gen ActionPy/TempCppGen/1146.cpp")])
def test_build_cpp_1146(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/118.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/118Gen ActionPy/TempCppGen/118.cpp")])
def test_build_cpp_118(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/120.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/120Gen ActionPy/TempCppGen/120.cpp")])
def test_build_cpp_120(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1207.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1207Gen ActionPy/TempCppGen/1207.cpp")])
def test_build_cpp_1207(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1234.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1234Gen ActionPy/TempCppGen/1234.cpp")])
def test_build_cpp_1234(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1239.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1239Gen ActionPy/TempCppGen/1239.cpp")])
def test_build_cpp_1239(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/124.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/124Gen ActionPy/TempCppGen/124.cpp")])
def test_build_cpp_124(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1261.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1261Gen ActionPy/TempCppGen/1261.cpp")])
def test_build_cpp_1261(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1312.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1312Gen ActionPy/TempCppGen/1312.cpp")])
def test_build_cpp_1312(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/132.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/132Gen ActionPy/TempCppGen/132.cpp")])
def test_build_cpp_132(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1329.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1329Gen ActionPy/TempCppGen/1329.cpp")])
def test_build_cpp_1329(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1347.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1347Gen ActionPy/TempCppGen/1347.cpp")])
def test_build_cpp_1347(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1372.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1372Gen ActionPy/TempCppGen/1372.cpp")])
def test_build_cpp_1372(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1379.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1379Gen ActionPy/TempCppGen/1379.cpp")])
def test_build_cpp_1379(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/139.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/139Gen ActionPy/TempCppGen/139.cpp")])
def test_build_cpp_139(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1410.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1410Gen ActionPy/TempCppGen/1410.cpp")])
def test_build_cpp_1410(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1423.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1423Gen ActionPy/TempCppGen/1423.cpp")])
def test_build_cpp_1423(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1457.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1457Gen ActionPy/TempCppGen/1457.cpp")])
def test_build_cpp_1457(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1475.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1475Gen ActionPy/TempCppGen/1475.cpp")])
def test_build_cpp_1475(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1483.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1483Gen ActionPy/TempCppGen/1483.cpp")])
def test_build_cpp_1483(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1491.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1491Gen ActionPy/TempCppGen/1491.cpp")])
def test_build_cpp_1491(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/15.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/15Gen ActionPy/TempCppGen/15.cpp")])
def test_build_cpp_15(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/150.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/150Gen ActionPy/TempCppGen/150.cpp")])
def test_build_cpp_150(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1544.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1544Gen ActionPy/TempCppGen/1544.cpp")])
def test_build_cpp_1544(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1553.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1553Gen ActionPy/TempCppGen/1553.cpp")])
def test_build_cpp_1553(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1561.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1561Gen ActionPy/TempCppGen/1561.cpp")])
def test_build_cpp_1561(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1600.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1600Gen ActionPy/TempCppGen/1600.cpp")])
def test_build_cpp_1600(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/162.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/162Gen ActionPy/TempCppGen/162.cpp")])
def test_build_cpp_162(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1637.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1637Gen ActionPy/TempCppGen/1637.cpp")])
def test_build_cpp_1637(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1657.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1657Gen ActionPy/TempCppGen/1657.cpp")])
def test_build_cpp_1657(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1658.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1658Gen ActionPy/TempCppGen/1658.cpp")])
def test_build_cpp_1658(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/167.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/167Gen ActionPy/TempCppGen/167.cpp")])
def test_build_cpp_167(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1670.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1670Gen ActionPy/TempCppGen/1670.cpp")])
def test_build_cpp_1670(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1671.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1671Gen ActionPy/TempCppGen/1671.cpp")])
def test_build_cpp_1671(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1683.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1683Gen ActionPy/TempCppGen/1683.cpp")])
def test_build_cpp_1683(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1685.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1685Gen ActionPy/TempCppGen/1685.cpp")])
def test_build_cpp_1685(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1686.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1686Gen ActionPy/TempCppGen/1686.cpp")])
def test_build_cpp_1686(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1696.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1696Gen ActionPy/TempCppGen/1696.cpp")])
def test_build_cpp_1696(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/17.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/17Gen ActionPy/TempCppGen/17.cpp")])
def test_build_cpp_17(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1702.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1702Gen ActionPy/TempCppGen/1702.cpp")])
def test_build_cpp_1702(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1704.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1704Gen ActionPy/TempCppGen/1704.cpp")])
def test_build_cpp_1704(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1727.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1727Gen ActionPy/TempCppGen/1727.cpp")])
def test_build_cpp_1727(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1738.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1738Gen ActionPy/TempCppGen/1738.cpp")])
def test_build_cpp_1738(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1757.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1757Gen ActionPy/TempCppGen/1757.cpp")])
def test_build_cpp_1757(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1793.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1793Gen ActionPy/TempCppGen/1793.cpp")])
def test_build_cpp_1793(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1814.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1814Gen ActionPy/TempCppGen/1814.cpp")])
def test_build_cpp_1814(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1883.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1883Gen ActionPy/TempCppGen/1883.cpp")])
def test_build_cpp_1883(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/191.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/191Gen ActionPy/TempCppGen/191.cpp")])
def test_build_cpp_191(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1913.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1913Gen ActionPy/TempCppGen/1913.cpp")])
def test_build_cpp_1913(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1944.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1944Gen ActionPy/TempCppGen/1944.cpp")])
def test_build_cpp_1944(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1953.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1953Gen ActionPy/TempCppGen/1953.cpp")])
def test_build_cpp_1953(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1969.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1969Gen ActionPy/TempCppGen/1969.cpp")])
def test_build_cpp_1969(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/1997.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/1997Gen ActionPy/TempCppGen/1997.cpp")])
def test_build_cpp_1997(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2007.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2007Gen ActionPy/TempCppGen/2007.cpp")])
def test_build_cpp_2007(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2009.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2009Gen ActionPy/TempCppGen/2009.cpp")])
def test_build_cpp_2009(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/205.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/205Gen ActionPy/TempCppGen/205.cpp")])
def test_build_cpp_205(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2085.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2085Gen ActionPy/TempCppGen/2085.cpp")])
def test_build_cpp_2085(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/209.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/209Gen ActionPy/TempCppGen/209.cpp")])
def test_build_cpp_209(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2129.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2129Gen ActionPy/TempCppGen/2129.cpp")])
def test_build_cpp_2129(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/216.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/216Gen ActionPy/TempCppGen/216.cpp")])
def test_build_cpp_216(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2171.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2171Gen ActionPy/TempCppGen/2171.cpp")])
def test_build_cpp_2171(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2192.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2192Gen ActionPy/TempCppGen/2192.cpp")])
def test_build_cpp_2192(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/22.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/22Gen ActionPy/TempCppGen/22.cpp")])
def test_build_cpp_22(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/221.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/221Gen ActionPy/TempCppGen/221.cpp")])
def test_build_cpp_221(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2216.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2216Gen ActionPy/TempCppGen/2216.cpp")])
def test_build_cpp_2216(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2225.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2225Gen ActionPy/TempCppGen/2225.cpp")])
def test_build_cpp_2225(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2246.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2246Gen ActionPy/TempCppGen/2246.cpp")])
def test_build_cpp_2246(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/225.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/225Gen ActionPy/TempCppGen/225.cpp")])
def test_build_cpp_225(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/228.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/228Gen ActionPy/TempCppGen/228.cpp")])
def test_build_cpp_228(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2304.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2304Gen ActionPy/TempCppGen/2304.cpp")])
def test_build_cpp_2304(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2312.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2312Gen ActionPy/TempCppGen/2312.cpp")])
def test_build_cpp_2312(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/232.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/232Gen ActionPy/TempCppGen/232.cpp")])
def test_build_cpp_232(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2336.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2336Gen ActionPy/TempCppGen/2336.cpp")])
def test_build_cpp_2336(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2342.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2342Gen ActionPy/TempCppGen/2342.cpp")])
def test_build_cpp_2342(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2356.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2356Gen ActionPy/TempCppGen/2356.cpp")])
def test_build_cpp_2356(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2369.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2369Gen ActionPy/TempCppGen/2369.cpp")])
def test_build_cpp_2369(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/242.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/242Gen ActionPy/TempCppGen/242.cpp")])
def test_build_cpp_242(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2433.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2433Gen ActionPy/TempCppGen/2433.cpp")])
def test_build_cpp_2433(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2444.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2444Gen ActionPy/TempCppGen/2444.cpp")])
def test_build_cpp_2444(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2476.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2476Gen ActionPy/TempCppGen/2476.cpp")])
def test_build_cpp_2476(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2487.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2487Gen ActionPy/TempCppGen/2487.cpp")])
def test_build_cpp_2487(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2529.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2529Gen ActionPy/TempCppGen/2529.cpp")])
def test_build_cpp_2529(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2538.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2538Gen ActionPy/TempCppGen/2538.cpp")])
def test_build_cpp_2538(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2575.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2575Gen ActionPy/TempCppGen/2575.cpp")])
def test_build_cpp_2575(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2580.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2580Gen ActionPy/TempCppGen/2580.cpp")])
def test_build_cpp_2580(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2581.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2581Gen ActionPy/TempCppGen/2581.cpp")])
def test_build_cpp_2581(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2583.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2583Gen ActionPy/TempCppGen/2583.cpp")])
def test_build_cpp_2583(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/260.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/260Gen ActionPy/TempCppGen/260.cpp")])
def test_build_cpp_260(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2617.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2617Gen ActionPy/TempCppGen/2617.cpp")])
def test_build_cpp_2617(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/264.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/264Gen ActionPy/TempCppGen/264.cpp")])
def test_build_cpp_264(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2645.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2645Gen ActionPy/TempCppGen/2645.cpp")])
def test_build_cpp_2645(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2646.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2646Gen ActionPy/TempCppGen/2646.cpp")])
def test_build_cpp_2646(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2661.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2661Gen ActionPy/TempCppGen/2661.cpp")])
def test_build_cpp_2661(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2670.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2670Gen ActionPy/TempCppGen/2670.cpp")])
def test_build_cpp_2670(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2671.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2671Gen ActionPy/TempCppGen/2671.cpp")])
def test_build_cpp_2671(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2673.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2673Gen ActionPy/TempCppGen/2673.cpp")])
def test_build_cpp_2673(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2696.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2696Gen ActionPy/TempCppGen/2696.cpp")])
def test_build_cpp_2696(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2707.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2707Gen ActionPy/TempCppGen/2707.cpp")])
def test_build_cpp_2707(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2739.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2739Gen ActionPy/TempCppGen/2739.cpp")])
def test_build_cpp_2739(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/274.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/274Gen ActionPy/TempCppGen/274.cpp")])
def test_build_cpp_274(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2765.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2765Gen ActionPy/TempCppGen/2765.cpp")])
def test_build_cpp_2765(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2766.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2766Gen ActionPy/TempCppGen/2766.cpp")])
def test_build_cpp_2766(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2786.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2786Gen ActionPy/TempCppGen/2786.cpp")])
def test_build_cpp_2786(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2789.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2789Gen ActionPy/TempCppGen/2789.cpp")])
def test_build_cpp_2789(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2807.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2807Gen ActionPy/TempCppGen/2807.cpp")])
def test_build_cpp_2807(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2809.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2809Gen ActionPy/TempCppGen/2809.cpp")])
def test_build_cpp_2809(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2810.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2810Gen ActionPy/TempCppGen/2810.cpp")])
def test_build_cpp_2810(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2813.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2813Gen ActionPy/TempCppGen/2813.cpp")])
def test_build_cpp_2813(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2824.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2824Gen ActionPy/TempCppGen/2824.cpp")])
def test_build_cpp_2824(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2831.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2831Gen ActionPy/TempCppGen/2831.cpp")])
def test_build_cpp_2831(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2834.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2834Gen ActionPy/TempCppGen/2834.cpp")])
def test_build_cpp_2834(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2840.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2840Gen ActionPy/TempCppGen/2840.cpp")])
def test_build_cpp_2840(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2846.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2846Gen ActionPy/TempCppGen/2846.cpp")])
def test_build_cpp_2846(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2859.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2859Gen ActionPy/TempCppGen/2859.cpp")])
def test_build_cpp_2859(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2861.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2861Gen ActionPy/TempCppGen/2861.cpp")])
def test_build_cpp_2861(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2864.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2864Gen ActionPy/TempCppGen/2864.cpp")])
def test_build_cpp_2864(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2865.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2865Gen ActionPy/TempCppGen/2865.cpp")])
def test_build_cpp_2865(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2866.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2866Gen ActionPy/TempCppGen/2866.cpp")])
def test_build_cpp_2866(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2867.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2867Gen ActionPy/TempCppGen/2867.cpp")])
def test_build_cpp_2867(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/29.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/29Gen ActionPy/TempCppGen/29.cpp")])
def test_build_cpp_29(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2923.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2923Gen ActionPy/TempCppGen/2923.cpp")])
def test_build_cpp_2923(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2928.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2928Gen ActionPy/TempCppGen/2928.cpp")])
def test_build_cpp_2928(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2938.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2938Gen ActionPy/TempCppGen/2938.cpp")])
def test_build_cpp_2938(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2958.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2958Gen ActionPy/TempCppGen/2958.cpp")])
def test_build_cpp_2958(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2960.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2960Gen ActionPy/TempCppGen/2960.cpp")])
def test_build_cpp_2960(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/2962.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/2962Gen ActionPy/TempCppGen/2962.cpp")])
def test_build_cpp_2962(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/299.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/299Gen ActionPy/TempCppGen/299.cpp")])
def test_build_cpp_299(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/3.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/3Gen ActionPy/TempCppGen/3.cpp")])
def test_build_cpp_3(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/300.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/300Gen ActionPy/TempCppGen/300.cpp")])
def test_build_cpp_300(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/303.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/303Gen ActionPy/TempCppGen/303.cpp")])
def test_build_cpp_303(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/3038.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/3038Gen ActionPy/TempCppGen/3038.cpp")])
def test_build_cpp_3038(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/3067.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/3067Gen ActionPy/TempCppGen/3067.cpp")])
def test_build_cpp_3067(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/3072.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/3072Gen ActionPy/TempCppGen/3072.cpp")])
def test_build_cpp_3072(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/3083.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/3083Gen ActionPy/TempCppGen/3083.cpp")])
def test_build_cpp_3083(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/3084.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/3084Gen ActionPy/TempCppGen/3084.cpp")])
def test_build_cpp_3084(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/3085.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/3085Gen ActionPy/TempCppGen/3085.cpp")])
def test_build_cpp_3085(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/3090.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/3090Gen ActionPy/TempCppGen/3090.cpp")])
def test_build_cpp_3090(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/3099.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/3099Gen ActionPy/TempCppGen/3099.cpp")])
def test_build_cpp_3099(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/32.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/32Gen ActionPy/TempCppGen/32.cpp")])
def test_build_cpp_32(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/332.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/332Gen ActionPy/TempCppGen/332.cpp")])
def test_build_cpp_332(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/337.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/337Gen ActionPy/TempCppGen/337.cpp")])
def test_build_cpp_337(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/337.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/337Gen ActionPy/TempCppGen/337.cpp")])
def test_build_cpp_337(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/365.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/365Gen ActionPy/TempCppGen/365.cpp")])
def test_build_cpp_365(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/375.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/375Gen ActionPy/TempCppGen/375.cpp")])
def test_build_cpp_375(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/377.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/377Gen ActionPy/TempCppGen/377.cpp")])
def test_build_cpp_377(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/387.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/387Gen ActionPy/TempCppGen/387.cpp")])
def test_build_cpp_387(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/39.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/39Gen ActionPy/TempCppGen/39.cpp")])
def test_build_cpp_39(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/39.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/39Gen ActionPy/TempCppGen/39.cpp")])
def test_build_cpp_39(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/409.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/409Gen ActionPy/TempCppGen/409.cpp")])
def test_build_cpp_409(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/419.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/419Gen ActionPy/TempCppGen/419.cpp")])
def test_build_cpp_419(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/42.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/42Gen ActionPy/TempCppGen/42.cpp")])
def test_build_cpp_42(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/447.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/447Gen ActionPy/TempCppGen/447.cpp")])
def test_build_cpp_447(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/462.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/462Gen ActionPy/TempCppGen/462.cpp")])
def test_build_cpp_462(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/5.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/5Gen ActionPy/TempCppGen/5.cpp")])
def test_build_cpp_5(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/514.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/514Gen ActionPy/TempCppGen/514.cpp")])
def test_build_cpp_514(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/516.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/516Gen ActionPy/TempCppGen/516.cpp")])
def test_build_cpp_516(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/516.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/516Gen ActionPy/TempCppGen/516.cpp")])
def test_build_cpp_516(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/518.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/518Gen ActionPy/TempCppGen/518.cpp")])
def test_build_cpp_518(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/53.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/53Gen ActionPy/TempCppGen/53.cpp")])
def test_build_cpp_53(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/57.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/57Gen ActionPy/TempCppGen/57.cpp")])
def test_build_cpp_57(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/58.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/58Gen ActionPy/TempCppGen/58.cpp")])
def test_build_cpp_58(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/589.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/589Gen ActionPy/TempCppGen/589.cpp")])
def test_build_cpp_589(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/590.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/590Gen ActionPy/TempCppGen/590.cpp")])
def test_build_cpp_590(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/606.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/606Gen ActionPy/TempCppGen/606.cpp")])
def test_build_cpp_606(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/62.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/62Gen ActionPy/TempCppGen/62.cpp")])
def test_build_cpp_62(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/63.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/63Gen ActionPy/TempCppGen/63.cpp")])
def test_build_cpp_63(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/64.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/64Gen ActionPy/TempCppGen/64.cpp")])
def test_build_cpp_64(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/661.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/661Gen ActionPy/TempCppGen/661.cpp")])
def test_build_cpp_661(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/670.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/670Gen ActionPy/TempCppGen/670.cpp")])
def test_build_cpp_670(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/687.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/687Gen ActionPy/TempCppGen/687.cpp")])
def test_build_cpp_687(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/689.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/689Gen ActionPy/TempCppGen/689.cpp")])
def test_build_cpp_689(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/70.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/70Gen ActionPy/TempCppGen/70.cpp")])
def test_build_cpp_70(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/705.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/705Gen ActionPy/TempCppGen/705.cpp")])
def test_build_cpp_705(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/706.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/706Gen ActionPy/TempCppGen/706.cpp")])
def test_build_cpp_706(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/712.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/712Gen ActionPy/TempCppGen/712.cpp")])
def test_build_cpp_712(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/713.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/713Gen ActionPy/TempCppGen/713.cpp")])
def test_build_cpp_713(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/72.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/72Gen ActionPy/TempCppGen/72.cpp")])
def test_build_cpp_72(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/739.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/739Gen ActionPy/TempCppGen/739.cpp")])
def test_build_cpp_739(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/740.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/740Gen ActionPy/TempCppGen/740.cpp")])
def test_build_cpp_740(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/746.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/746Gen ActionPy/TempCppGen/746.cpp")])
def test_build_cpp_746(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/82.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/82Gen ActionPy/TempCppGen/82.cpp")])
def test_build_cpp_82(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/828.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/828Gen ActionPy/TempCppGen/828.cpp")])
def test_build_cpp_828(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/83.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/83Gen ActionPy/TempCppGen/83.cpp")])
def test_build_cpp_83(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/867.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/867Gen ActionPy/TempCppGen/867.cpp")])
def test_build_cpp_867(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/872.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/872Gen ActionPy/TempCppGen/872.cpp")])
def test_build_cpp_872(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/889.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/889Gen ActionPy/TempCppGen/889.cpp")])
def test_build_cpp_889(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/894.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/894Gen ActionPy/TempCppGen/894.cpp")])
def test_build_cpp_894(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/907.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/907Gen ActionPy/TempCppGen/907.cpp")])
def test_build_cpp_907(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/924.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/924Gen ActionPy/TempCppGen/924.cpp")])
def test_build_cpp_924(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/931.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/931Gen ActionPy/TempCppGen/931.cpp")])
def test_build_cpp_931(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/935.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/935Gen ActionPy/TempCppGen/935.cpp")])
def test_build_cpp_935(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/938.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/938Gen ActionPy/TempCppGen/938.cpp")])
def test_build_cpp_938(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/94.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/94Gen ActionPy/TempCppGen/94.cpp")])
def test_build_cpp_94(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/968.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/968Gen ActionPy/TempCppGen/968.cpp")])
def test_build_cpp_968(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

@pytest.mark.parametrize("test_case", [("ActionPy/TempCppGen/992.cpp", "g++ -std=c++17 -o ActionPy/TempCppGen/cpp17/992Gen ActionPy/TempCppGen/992.cpp")])
def test_build_cpp_992(test_case):
    cpp_file, build_command = test_case
    try:
        subprocess.check_call(build_command.split(), stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Failed to build C++ code: {e}")

