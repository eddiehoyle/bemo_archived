#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import pybemo

def main():
    pybemo.init();

    nodeA = pybemo.create("py")
    print nodeA
    print nodeA.execute()

if __name__ == '__main__':
    main()