#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import pybemo

SNIPPET = r"""
sys.stdout.write('hi\n')
"""
sumA = None
sumB = None

def testA():
    global sumA, sumB
    sumA = pybemo.create_node("sum")
    sumB = pybemo.create_node("sum")

def main():
    print "1"
    pybemo.init()
    # sumA = pybemo.create_node("sum")
    testA()
    nodes = pybemo.ls()
    print "Nodes:", len(nodes)
    print "IDs:", sumA.getObjectID(), sumB.getObjectID()

if __name__ == '__main__':
    main()
