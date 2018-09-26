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

    nodeA = pybemo.create("sum")
    # nodeB = pybemo.create("multiply")
    # nodeA.set_input("valueA", 2)
    # nodeA.set_input("valueB", 3)
    # print nodeA
    # print nodeB

    nodeA = None

    # print "Valid A1:", nodeA.valid()
    # print "Valid B1:", nodeB.valid()

    # print "Removing sum (py)"
    # pybemo.remove(nodeA)
    # print "Removing multiply (cpp)"
    # pybemo.remove(nodeB)

    # print "Valid A2:", nodeA.valid()
    # print "Valid B2:", nodeB.valid()


    # nodeA = pybemo.create("snippet")
    # nodeB = pybemo.create("multiply")
    #
    # print "A:", pybemo.count()
    #
    # pybemo.remove(nodeA)
    # pybemo.remove(nodeB)
    #
    # print "B:", pybemo.count()

if __name__ == '__main__':
    main()
