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
    ws = pybemo.Workspace.create()
    sumA = pybemo.Node.create("sum", "sum1")
    sumB = pybemo.Node.create("sum", "sum2")


if __name__ == '__main__':
    main()
