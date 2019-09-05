import subprocess as sp
import os

f = open('file_list.txt', 'r')
while True:
    line = f.readline()
    if not line:
        break
    os.system('sudo chmod 774 ' + line)

sp.call(['git', 'add', '.'])
sp.call(['git', 'commit', '-m', 'test'])
sp.call(['git', 'push', 'origin', 'master'])