# A Tool for creating Markdown file
import os
import time
import re
import pandas as pd



def LC_generate_markdown_file(directory, output_file):
    url = "https://raw.githubusercontent.com/zerotrac/leetcode_problem_rating/main/ratings.txt"
    df = pd.read_table(url)
    ps = {}
    for i in range(len(df)):
        ps[int(df.ID[i])] = df.Rating[i]
        # print(ps[int(df.ID[i])])

    with open(output_file, 'w+', encoding="UTF-8") as f:
        f.write("# LeetCode List\n\n")
        f.write("| Question | Rating | Difficulty | Tags |\n")
        f.write("|---|---|---|---|\n")

        for root, dirs, files in os.walk(directory):
            for file in files:
                file_path = os.path.join(root, file)
                file_name = os.path.basename(file_path)
                if (file_name[-3:] != ".md"):
                    continue
                file_name = file_name[:-3]
                relative_path = os.path.relpath(file_path, directory)
                
                tags ,Diff = ReDiff(f"{directory}/{relative_path}")
                Rating = 0
                # Extract number using regular expression
                number = re.match(r'^(\d+)', relative_path)
                if number:
                    extracted_number = number.group(1)
                    # print(f"Title: {relative_path}\nExtracted Number: {extracted_number}")
                    Rating = 0 if int(extracted_number) not in ps else ps[int(extracted_number)]
                else:
                    # print(f"No number found in the title: {relative_path}\n")
                    pass
                # print(tags)
                # print(Diff)
                # print(Rating)
                
                Dif_name = "" if Diff == None else f"{Diff}"
                tags_name = "" if tags == [] else ', '.join(str(t) for t in tags)
                Rating_name = "" if Rating == 0 else f"{str(Rating)}"

                relative_path = relative_path.replace(" ", "%20")
                markdown_link = f"[{file_name}]({directory}/{relative_path})"
                result = f"| {markdown_link} | {Rating_name} | {Dif_name} | {tags_name} |\n"
                f.write(f"{result}")

    print(f"Markdown file generated: {output_file}")

def LG_generate_markdown_file(directory, output_file):
    with open(output_file, 'w+', encoding="UTF-8") as f:
        f.write("# luogu List\n\n")
        f.write("| Question | Difficulty | Tags |\n")
        f.write("|---|---|---|\n")

        for root, dirs, files in os.walk(directory):
            for file in files:
                file_path = os.path.join(root, file)
                file_name = os.path.basename(file_path)
                if (file_name[-3:] != ".md"):
                    continue
                file_name = file_name[:-3]
                relative_path = os.path.relpath(file_path, directory)
                
                tags ,Diff = ReDiff(f"{directory}/{relative_path}")
                
                Dif_name = "" if Diff == None else f"{Diff}"
                tags_name = "" if tags == [] else ', '.join(str(t) for t in tags)

                relative_path = relative_path.replace(" ", "%20")
                markdown_link = f"[{file_name}]({directory}/{relative_path})"
                result = f"| {markdown_link} | {Dif_name} | {tags_name} |\n"
                f.write(f"{result}")

    print(f"Markdown file generated: {output_file}")

def ReDiff(path: str):
    content = ReadMD(path)

    # Extract tags using regular expression
    Tp = r'tags:\s*\[(.*?)\]'
    difficulty_pattern = r'Difficulty:\s*"([^"]+)"'

    difficulty = None
    tags = []

    matches = re.findall(Tp, content, re.DOTALL)
    if matches:
        tags = [tag.strip() for tag in matches[0].split(',')]
        tags = [tag[1:-1] for tag in tags ]
        print("Tags found:", tags)
    else:
        # print("No tags found.")
        pass
    
    difficulty_match = re.search(difficulty_pattern, content)
    if difficulty_match:
        difficulty = difficulty_match.group(1)
        print("Difficulty:", difficulty)
    else:
        # print("Difficulty not found.")
        pass
        
    return tags, difficulty  

def ReadMD(filename: str):
    print("Loading:" + filename)
    with open(filename, "r", encoding="UTF-8") as file:
        content = file.read()
    return content

# Specify the directory to search for files
directory_to_search = "./leetcode"

# Specify the output Markdown file
output_markdown_file = "LeetCodeList.md"

# Generate the Markdown file
LC_generate_markdown_file(directory_to_search, output_markdown_file)

# luogu
directory_to_search = "./luogu"

# Specify the output Markdown file
output_markdown_file = "luoguList.md"

LG_generate_markdown_file(directory_to_search, output_markdown_file)