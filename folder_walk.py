#!/usr/bin/python

import os
import subprocess
count = 0
for (dirname, dirs, files) in os.walk('/home/srlkhmi/Desktop/Madness/warmfuzz'): #specify path for walk
   for filename in files:
        thefile = os.path.join(dirname,filename)
        print thefile
        count = count + 1
print 'Files:', count




