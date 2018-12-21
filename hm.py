<<<<<<< HEAD
import sys
from Naked.toolshed.shell import muterun_js

response = muterun_js('hmwait.js')
if response.exitcode == 0:
	waittime = response.stdout
	print(waittime)
else:
	sys.stderr.write(response.stderr)

=======
import sys
from Naked.toolshed.shell import muterun_js

response = muterun_js('hmwait.js')
if response.exitcode == 0:
	waittime = response.stdout
	print(waittime)
else:
	sys.stderr.write(response.stderr)

>>>>>>> 70437755a8b59ef5d1e050f19d45bd515eb1c222
