#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import pybemo

SNIPPET = r"""
sys.stdout.write('hi\n')
"""

def main():
    print "1"
    pybemo.init()
    sumA = pybemo.create_node("sum")
    print "Sum node: %s is valid: %s" % (sumA, sumA.isValid())

if __name__ == '__main__':
    main()
