
import os
import subprocess
import time

startTime = time.time()

os.chdir('/Users/jinhyuncheong/jcheong0428.github.io/assets/')

while True:
	diff = time.time() - startTime
	# print diff
	if  diff > 30:
		command = 'git add linelength.txt'
		subprocess.call(command, shell=True)
		command = 'git commit -m "update line"'
		subprocess.call(command, shell=True)
		command = 'git push'
		subprocess.call(command, shell=True)
		startTime = time.time()