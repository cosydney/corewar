import subprocess as sp
import sys

dump = int(sys.argv[1])
files = sys.argv[2:]

out1 = sp.check_output(['./corewar', '-dump', str(dump)] + files).split('\n')[:-1]
out1 = map(lambda x: x[9:], out1[2 + len(files):])
o1 = [out1[x] + " " + out1[x + 1] for x in range(0, len(out1), 2)]

out2 = sp.check_output(['./corewar_o', '-d', str(dump)] + files).split('\n')[:-1]
o2 = map(lambda x: x[9:-1], out2[1 + len(files):])

diff1 = ''
diff2 = ''

for line in o1:
    diff1 += line + '\n'
for line in o2:
    diff2 += line + '\n'

print sp.check_output(['diff', '<(echo "' + diff1 + '")', '<(echo "' + diff2 + '")'])
