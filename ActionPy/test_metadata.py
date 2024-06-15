from .TestBase import TestBase
import pytest

@pytest.mark.parametrize("file_path", "leetcode\\3. 无重复字符的最长子串.md")
def test_1(file_path):
    TestBase.metadata_format(file_path)