import os

markdown_files = [os.path.join('leetcode/', f) for f in os.listdir('leetcode') if f.endswith('.md')]
print(markdown_files)

# https://regex101.com/r/EXWeym/2

with open('ActionPy/test_metadata.py', 'w+', encoding='utf-8') as file:
    file.write("""
from SetUpForTest.TestMetaData import pytest
from SetUpForTest.TestMetaData import re
from SetUpForTest.TestMetaData import metadata_format
""")


    for i, file_path in enumerate(markdown_files):
        file_name = os.path.splitext(os.path.basename(file_path))[0]
        function_name = f'test_{file_name.split(". ")[0]}'
        file.write(f'@pytest.mark.parametrize("file_path", ["{file_path}"])\n')
        file.write(f'def {function_name}(file_path):\n')
        file.write('    metadata_format(file_path)\n\n')

print('test_metadata.py file created successfully!')

# const text = `
# ---
# Difficulty: "Easy"
# tags: ["枚舉"]
# ---

# > Problem: [1696. 跳跃游戏 VI](https://leetcode.cn/problems/jump-game-vi/description/)
# `;

# const regex = /---\nDifficulty: "(?<difficulty>\w+)"\ntags: \[(?<tags>[\w, "]+)\]\n---/;
# const match = text.match(regex);

# console.log(match.groups.difficulty); // "Easy"
# console.log(match.groups.tags); // '"枚舉"'