#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import pybemo

def main():
    pybemo.init();

    nodeA = pybemo.create("py")
    print "nodeA:", nodeA
    print "nodeA: %s" % nodeA.execute()

    nodeB = pybemo.create("cpp")
    print "nodeB:", nodeB
    print "nodeB: %s" % nodeB.execute()

    pybemo.remove(nodeA.getName());
    pybemo.remove(nodeB.getName());

    print nodeA;
    print nodeB;

if __name__ == '__main__':
    main()