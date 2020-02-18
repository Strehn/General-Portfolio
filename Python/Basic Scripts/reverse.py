#!/usr/bin/env python    

import os
#creating a new file then copying text into it and replacing the OG
f=open("temp.txt", "w+")
for line in reversed(open("filename").readlines()):
    f.write(line.rstrip())
    f.write("\n")
f.close()
with open("temp.txt") as f:
    with open("filename", "w") as f1:
        for line in f:
            f1.write(line)
f.close()
f1.close()
os.remove("temp.txt")
