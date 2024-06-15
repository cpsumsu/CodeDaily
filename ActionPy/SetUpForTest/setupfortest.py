import os
markdown_files = [os.path.join('leetcode', f) for f in os.listdir('leetcode') if f.endswith('.md')]
print(markdown_files)

with open('ActionPy/test_metadata.py', 'w+') as file:
    file.write('import pytest\n')
    
    file.write("""
    import re
    import pytest

    class TestBase:
        def metadata_format(file_path):
            \"\"\"
            Check if the given Markdown file has the expected metadata format.
            \"\"\"
            with open(file_path, 'r') as f:
                content = f.read()
                
                # Check if the file starts with the expected metadata format
                metadata = re.match(r'^---\\nDifficulty: "(\w+)"\\ntags: (\[.*?\])\\n(.*?)\\n---\\n', content)
                assert metadata is not None, f'Metadata format is missing or incorrect in {file_path}'
                
                difficulty = metadata.group(1)
                tags = metadata.group(2)
                extra_properties = metadata.group(3).strip().split('\\n')
                
                # Check if Difficulty and tags are present
                assert difficulty is not None, f'Difficulty is missing in {file_path}'
                assert tags is not None, f'Tags is missing in {file_path}'
                
                # Check for extra properties
                for prop in extra_properties:
                    if prop.startswith('name:'):
                        pass  # Ignore the "name" property
                    else:
                        assert False, f'Unexpected property "{prop.split(":")[0]}" in {file_path}'
    """)

    for i, file_path in enumerate(markdown_files):
        function_name = f'test_{i+1}'
        file.write(f'@pytest.mark.parametrize("file_path", ["{file_path}"])\n')
        file.write(f'def {function_name}(file_path):\n')
        file.write('    TestBase.metadata_format(file_path)\n\n')

print('test_metadata.py file created successfully!')
