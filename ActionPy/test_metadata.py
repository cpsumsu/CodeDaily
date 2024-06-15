import os
import re

def test_metadata_format():
    """
    Check if all Markdown files in the ./leetcode/ directory have the expected metadata format.
    """
    for root, _, files in os.walk('./leetcode'):
        for file in files:
            if file.endswith('.md'):
                with open(os.path.join(root, file), 'r') as f:
                    content = f.read()
                    
                    # Check if the file starts with the expected metadata format
                    metadata = re.match(r'^---\nDifficulty: "(\w+)"\ntags: (\[.*?\])\n(.*?)\n---\n', content)
                    if metadata is None:
                        assert False, f'Metadata format is missing or incorrect in {os.path.join(root, file)}'
                    else:
                        difficulty = metadata.group(1)
                        tags = metadata.group(2)
                        extra_properties = metadata.group(3).strip().split('\n')
                        
                        # Check if Difficulty and tags are present
                        assert difficulty is not None, f'Difficulty is missing in {os.path.join(root, file)}'
                        assert tags is not None, f'Tags is missing in {os.path.join(root, file)}'
                        
                        # Check for extra properties
                        for prop in extra_properties:
                            if prop.startswith('name:'):
                                pass  # Ignore the "name" property
                            else:
                                assert False, f'Unexpected property "{prop.split(":")[0]}" in {os.path.join(root, file)}'