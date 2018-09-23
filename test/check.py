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

    nodeA = pybemo.create2("sum")
    nodeA.set_input("valueA", 2)
    nodeA.set_input("valueB", 3)

    # nodeB = pybemo.create2("multiply")
    # nodeB.set_input("valueA", 3)
    # nodeB.set_input("valueB", 5)

    pybemo.execute(nodeA)
    # pybemo.execute(nodeB)

    # pybemo.remove2(nodeA)
    # pybemo.remove2(nodeB)


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
