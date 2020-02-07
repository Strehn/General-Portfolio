#!/usr/bin/env python    

import os
import shutil

#check if first character is a number, if not add if so remove
checkcase = 2
numlist = ['0','1','2','3','4','5','6','7','8','9']
with open("testfile.txt") as f:
    for line in f:
        for ch in line:
            if(ch in numlist):
                #there are line numbers
                checkcase = 0
                break
            else:
                #there are no line numbers
                checkcase = 1

if(checkcase == 0):
    #there are line numbers                                                             
    f=open("testfile.txt", "r")
    f1=open("temp.txt", "w")
    for line in f:
        sline = line.split(" ")
        rline = sline[1:]
        jline = " ".join(rline)
        f1.write(jline)
else:
    #there are no line numbers
    f=open("testfile.txt", "r")
    lines=f.readlines()
    text = ['%d %s' %(i, line) for i, line in enumerate(lines)]
    fadd=open("temp.txt","w")
    fadd.writelines(str("".join(text)))
    fadd.close()
#os.remove("testfile.txt")
#shutil.copy('temp.txt', 'testfile.txt')


f=open("temp.txt", "r")
f1=open("testfile.txt", "w")
for line in f:
    #print (line)
    f1.write(line)
f.close()
f1.close()
#copys temp into the file                                                                         
#with open("temp.txt", "r") as f:
 #   with open("testfile.txt", "w") as f1:
  #      for line in f:
   #         f1.write(line)
os.remove("temp.txt")
#EOF
