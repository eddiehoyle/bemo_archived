#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import pybemo

SNIPPET = r"""
sys.stdout.write('hi\n')
"""

def main():
    pybemo.initialise();

    nodeA = pybemo.create("snippet")
    nodeB = pybemo.create("multiply")
    a = pybemo.ls()
    # pybemo.remove(nodeA)
    # pybemo.remove(nodeB)

if __name__ == '__main__':
    main()
