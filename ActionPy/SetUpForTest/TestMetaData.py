import re
import pytest

def metadata_format(file_path):
    """
    Check if the given Markdown file has the expected metadata format.
    """
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()
        
        # Check if the file starts with the expected metadata format
        metadata = re.match(r'---\s*\n(?:title:\s*"(?P<title>[\w.\- \'\,\|\[\-\=\?\/]+)"\s*\n)?(?:Difficulty:\s*"(?P<difficulty>\w+)"\s*\n)?(?:tags:\s*\[(?P<tags>[\w.\- \'\,\|\[\-\=\?\/"]*)\]\s*\n)?---', content)
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