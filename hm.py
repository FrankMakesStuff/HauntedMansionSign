import sys
from Naked.toolshed.shell import muterun_js

response = muterun_js('hmwait.js')
if response.exitcode == 0:
	waittime = response.stdout
	print(waittime)
else:
	sys.stderr.write(response.stderr)

