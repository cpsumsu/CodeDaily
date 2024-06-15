import os

markdown_files = [os.path.join('leetcode/', f) for f in os.listdir('leetcode') if f.endswith('.md')]
print(markdown_files)

# https://regex101.com/r/1lTwsY/1

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
            metadata = re.match(r'---\\nDifficulty: "(?P<difficulty>\w+)"\\ntags: \[(?P<tags>[\w, "]+)\](\\ntitle: "(?P<title>\w+)")?\\n---', content)
            assert metadata is not None, f'Metadata format is missing or incorrect in {file_path}'
            
            difficulty = metadata.group(1)
            tags = metadata.group(2)
            extra_properties = metadata.group(3)
            
            # Check if Difficulty and tags are present
            assert difficulty is not None, f'Difficulty is missing in {file_path}'
            assert tags is not None, f'Tags is missing in {file_path}'
            
            # Check for extra properties
            if extra_properties is not None:
                extra_properties = extra_properties.strip().split('\\n')
                for prop in extra_properties:
                    if prop.startswith('title:'):
                        pass  # Ignore the "title" property
                    else:
                        assert False, f'Unexpected property "{prop.split(":")[0]}" in {file_path}'
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