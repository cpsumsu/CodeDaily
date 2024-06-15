import os
markdown_files = [os.path.join('leetcode', f) for f in os.listdir('leetcode') if f.endswith('.md')]
print(markdown_files)

with open('test_metadata.py', 'w') as file:
    file.write('import pytest\n')
    file.write('from .SetUpForTest.TestBase import TestBase\n\n')

    for i, file_path in enumerate(markdown_files):
        function_name = f'test_{i+1}'
        file.write(f'@pytest.mark.parametrize("file_path", ["{file_path}"])\n')
        file.write(f'def {function_name}(file_path):\n')
        file.write('    TestBase.metadata_format(file_path)\n\n')

print('test_metadata.py file created successfully!')
