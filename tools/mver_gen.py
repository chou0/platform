#!/usr/bin/python3

import datetime
import sys

def gen_version(ver):
    str = 'v' + ver + '.'
    now = datetime.datetime.now()
    str += now.strftime('%y%m%d%H%M%S')
    print(str)

gen_version(sys.argv[1])