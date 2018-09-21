#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import pybemo

SNIPPET = r"""
sys.stdout.write('hi\n')
"""

def main():
    pybemo.initialise()

    nodeA = pybemo.create("snippet")
    nodeB = pybemo.create("multiply")

    print "A:", pybemo.count()

    pybemo.remove(nodeA)
    pybemo.remove(nodeB)

    print "B:", pybemo.count()

def test():

    nodeA.connect("result", nodeB, "valueA")
    pybemo.connect(nodeA, "result", nodeB, "valueA")


if __name__ == '__main__':
    main()
