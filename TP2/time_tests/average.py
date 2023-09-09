#!python3

import sys
import os
from typing import List, IO


def get_times(fhnd:IO, ls:List[float]):
    for line in fhand:
        if "real" in line:
            s:str = line.split("m")
            tmp_s:str = s[1].strip('s\n')
            tmp_s = tmp_s.replace(",",".")
            tmp:float = float(tmp_s)
            ls.append(tmp)
    return ls

def write_results(fhand:IO, fname:str, ls:List[float]):
    name_str:str = fname + ": "
    fhand.write(name_str)
    fhand.write("(")
    count:int = 0
    for i in ls:
        if count != (len(ls)-1): 
            s:str = str(i) + " + "
        else: 
            s:str = str(i)
        count += 1
        fhand.write(s)
    s:str = ") / 10 = " + str(round((sum(ls) / 10 *1000), 4)) + "\n"
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
            times:List[float] = get_times(fhand, [])
            fname:str = filename.strip(".txt")
            write_results(output, fname, times)