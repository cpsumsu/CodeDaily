import os
from pathlib import Path

test_path = 'leetcode'
markdown_files = [Path(test_path) / f for f in os.listdir(test_path) if f.endswith('.md')]

with open('ActionPy/test_metadata.py', 'w', encoding='utf-8') as file:
    file.write("""from SetUpForTest.TestMetaData import metadata_format
import pytest

""")


    for i, file_path in enumerate(markdown_files):
        file_name = os.path.basename(file_path)
        function_name = f'test_{file_name.split(". ")[0]}'
        
        file.write(f'@pytest.mark.parametrize("file_path", ["{file_path}"])\n')
        file.write(f'def {function_name}(file_path):\n')
        file.write('    metadata_format(file_path)\n\n')

print('test_metadata.py file created successfully!')
