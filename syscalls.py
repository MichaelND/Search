#!/usr/bin/env python2.7

import os
import sys
from subprocess import Popen, PIPE

args = sys.argv[1:] #command to be executed
command = ""

while len(args):
	command = command + " " + args.pop(0)

output = 'strace -c {}'.format(command)
o = Popen(output, stdout=PIPE, stderr=PIPE, shell=True)

stdout,stderr = o.communicate()

print '{}'.format(stderr)
