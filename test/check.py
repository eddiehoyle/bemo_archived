#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import pybemo

def main():
    pybemo.initialise();

    nodeA = pybemo.create("py")
    # print "nodeA:", nodeA
    # print "nodeA: %s" % nodeA.execute()

    nodeB = pybemo.create("cpp")
    # print "nodeB:", nodeB
    # print "nodeB: %s" % nodeB.execute()
    #
    # pybemo.remove(nodeA.getName());
    # pybemo.remove(nodeB.getName());

    nodeA.connect("output", nodeB, "cpp_valueA")

    print nodeA;
    print nodeB;

if __name__ == '__main__':
    main()