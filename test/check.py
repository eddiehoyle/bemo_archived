#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import pybemo

SNIPPET = r"""
sys.stdout.write('hi\n')
"""

def main():
    pybemo.init()
    # graphA = pybemo.create_graph("graphA")
    # nodeA = pybemo.create_node("nodeA")
    # print "A : nodeA is valid:", nodeA.isValid()
    # print "A : graphA is valid:", graphA.isValid()
    # pybemo.delete(nodeA)
    # pybemo.delete(graphA)
    # print "B : nodeA is valid:", nodeA.isValid()
    # print "B : graphA is valid:", graphA.isValid()

if __name__ == '__main__':
    main()
