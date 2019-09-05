import subprocess as sp
import os

f = open('file_list.txt', 'r')
while True:
    line = f.readline()
    if not line:
        break
    os.system('sudo chmod 664 ' + line)

sp.call(['git', 'add', '.'])
sp.call(['git', 'commit', '-m', '2019/09/05'])
sp.call(['git', 'push', 'origin', 'master'])