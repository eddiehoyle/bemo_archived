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
    # nodeA = pybemo.create("sum")
    # nodeB = pybemo.create("sum")
    # nodeA.connect("result", nodeB, "valueA")

    # n = pybemo.test_create()

    # nodeA = pybemo.AbstractNode()
    nodeB = pybemo.create("snippet")
    # nodeC = pybemo.create("multiply")

    # nodeA.setInput("snippet", "1")
    # nodeA.execute()

    # nodeC = pybemo.create("multiply")
    # print nodeA
    # print nodeC
    # nodeA.setInput("snippet", SNIPPET)
    # nodeA.execute()

if __name__ == '__main__':
    main()
    print 'sf'