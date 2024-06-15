import os

markdown_files = [os.path.join('leetcode/', f) for f in os.listdir('leetcode') if f.endswith('.md')]
print(markdown_files)

# https://regex101.com/r/EXWeym/2

with open('ActionPy/test_metadata.py', 'w+', encoding='utf-8') as file:
    file.write('import pytest\n')
    
    file.write(
"""
import re
class TestBase:
    def metadata_format(file_path):
        \"\"\"
        Check if the given Markdown file has the expected metadata format.
        \"\"\"
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
            
            # Check if the file starts with the expected metadata format
            metadata = re.match(r'---\s*\\n(?:title:\s*"(?P<title>[\w.\- \\'\,\|\[\-\=\?\/]+)"\s*\\n)?(?:Difficulty:\s*"(?P<difficulty>\w+)"\s*\\n)?(?:tags:\s*\[(?P<tags>[\w.\- \\'\,\|\[\-\=\?\/"]*)\]\s*\\n)?---', content)
            if metadata is None:
                pytest.fail(f'Metadata format is missing or incorrect')
            
            difficulty = metadata.group('difficulty')
            tags = metadata.group('tags')
            title = metadata.group('title')
            extra_properties = metadata.group(3)
            
            # Check if Difficulty and tags are present
            if difficulty is None:
                pytest.fail(f'Difficulty is missing')
            if tags is None:
                pytest.fail(f'Tags is missing')
            
            # Check for extra properties
            pass  # Ignore the "title" property
""")

    for i, file_path in enumerate(markdown_files):
        file_name = os.path.splitext(os.path.basename(file_path))[0]
        function_name = f'test_{file_name.split(". ")[0]}'
        file.write(f'@pytest.mark.parametrize("file_path", ["{file_path}"])\n')
        file.write(f'def {function_name}(file_path):\n')
        file.write('    TestBase.metadata_format(file_path)\n\n')

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