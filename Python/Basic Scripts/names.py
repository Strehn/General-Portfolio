#!/usr/bin/env python

import os
import glob
files = glob.glob('*.cxx')
for file in files:
    parts = file.split('.') #name.cxx
    new_name = '{}.cpp'.format(parts[0]) #name.cpp
    os.rename(file, new_name)
