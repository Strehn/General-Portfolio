#!/usr/bin/env python    

import os
import shutil

#checking if file exists
#exists = os.path.isdir('./.backup')
#print (exists)
#if not exists:
    #os.makedirs('./.backup')
dest = '.backup'
cd = os.getcwd()
scd = cd.split("/")
ncd = scd[-1]
dest = dest +"/"+ ncd
print (dest)

#put files into .backup
def copyDirectory(src, dest):
    try:
        shutil.copytree(src, dest)
    except shutil.Error as e:
        print('Removing previous backup directory')
        #remove the previous directory
        shutil.rmtree('.backup')
        #os.rmdir('.backup')
        shutil.copytree(src, dest)
    except OSError as e:
        print('Removing previous backup directory')
        #remove the previous directory
        shutil.rmtree('.backup')
        #os.rmdir('.backup')
        shutil.copytree(src, dest)

copyDirectory('./' , dest)
