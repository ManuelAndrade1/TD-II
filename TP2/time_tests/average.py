#!python3

import sys
import os
from typing import List, IO


def get_times(fhnd:IO, ls:List[int]):
    for line in fhand:
        if "real" in line:
            s:str = line.split(",")
            tmp:int = int(s[1].strip("s\n"))
            ls.append(tmp)
    return ls

def write_results(fhand:IO, fname:str, ls:List[int]):
    name_str:str = fname + ": "
    fhand.write(name_str)
    fhand.write("(")
    for i in times:
        if i != times[len(times)-1]: s:str = str(i) + " + "
        else: s:str = str(i)
        fhand.write(s)
    s:str = ") / 10 = " + str(sum(times) / 10) + "\n"
    fhand.write(s)



# Specify the directory path you want to search in
directory_path:str = sys.argv[1]
fout:str = sys.argv[2]
output:IO = open(fout, "w")

# Iterate over all files and directories in the specified directory
for root, dirs, files in os.walk(directory_path):
    for filename in files:
        # Check if the file has a .txt extension
        if filename.endswith(".txt"):
            # Print the ful path of the .txt file
            fhand:IO = open(os.path.join(root, filename))
            times:List[int] = get_times(fhand, [])
            fname:str = filename.strip(".txt")
            write_results(output, fname, times)