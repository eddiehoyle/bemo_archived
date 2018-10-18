#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import bmo

SNIPPET = r"""
sys.stdout.write('hi\n')
"""

def main():
    print "1"
    bmo.api.init()
    print bmo.core
    print "1"


if __name__ == '__main__':
    main()
