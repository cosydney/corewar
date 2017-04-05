import subprocess as sp
import sys

dump = int(sys.argv[1])

out1 = sp.check_output(['./corewar', '-dump', str(dump)] + sys.argv[2:])
print out1
