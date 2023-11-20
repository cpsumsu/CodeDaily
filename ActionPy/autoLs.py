# A Tool for creating Markdown file
import os
import time

def generate_markdown_file(directory, output_file):
    with open(output_file, 'w+', encoding="UTF-8") as f:
        f.write("# LeetCode List\n\n")
        f.write("| Filename | Link |\n")
        f.write("|---|---|\n")

        for root, dirs, files in os.walk(directory):
            for file in files:
                file_path = os.path.join(root, file)
                file_name = os.path.basename(file_path)
                relative_path = os.path.relpath(file_path, directory)
                relative_path = relative_path.replace(" ", "%20")
                markdown_link = f"[{file_name}]({directory}/{relative_path})"
                f.write(f"| {file_name} | {markdown_link} |\n")

    print(f"Markdown file generated: {output_file}")

# Specify the directory to search for files
directory_to_search = "./leetcode"

# Specify the output Markdown file
output_markdown_file = "LeetCodeList.md"

# Generate the Markdown file
generate_markdown_file(directory_to_search, output_markdown_file)