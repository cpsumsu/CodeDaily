import re
import pytest

class TestBase:
    def metadata_format(file_path):
        """
        Check if the given Markdown file has the expected metadata format.
        """
        with open(file_path, 'r') as f:
            content = f.read()
            
            # Check if the file starts with the expected metadata format
            metadata = re.match(r'^---\nDifficulty: "(\w+)"\ntags: (\[.*?\])\n(.*?)\n---\n', content)
            if metadata is None:
                pytest.fail(f'Metadata format is missing or incorrect in {file_path}')
            
            difficulty = metadata.group(1)
            tags = metadata.group(2)
            extra_properties = metadata.group(3).strip().split('\n')
            
            # Check if Difficulty and tags are present
            if difficulty is None:
                pytest.fail(f'Difficulty is missing')
            if tags is None:
                pytest.fail(f'Tags is missing')
            
            # Check for extra properties
            for prop in extra_properties:
                if prop.startswith('name:'):
                    pass  # Ignore the "name" property
                else:
                    assert f'Unexpected property "{prop.split(":")[0]}" in {file_path}'