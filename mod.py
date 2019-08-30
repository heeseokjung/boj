import os

files = ['boj_10803.cpp', 'boj_10835.cpp', 'boj_1103.cpp', 'boj_1162.cpp', 'boj_1613.cpp',
         'boj_16637.cpp', 'boj_17136.cpp', 'boj_1786.cpp', 'boj_4948.cpp']

for f in files:
    s = 'sudo chmod 664 ' + f
    os.system(s)