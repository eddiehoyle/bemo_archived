#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import pybemo

def main():
    pybemo.initialise();
    nodeA = pybemo.create("sum")
    nodeB = pybemo.create("sum")
    nodeA.connect("result", nodeB, "valueA")

if __name__ == '__main__':
    main()