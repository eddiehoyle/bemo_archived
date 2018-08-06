#!/usr/bin/env python

import os
import sys
sys.path.insert(0, os.path.abspath("../build"))

import pybemo

class PyNode(pybemo.AbstractNode):

    def execute(self):
        print "Executing %s!" % (self.__class__.__name__)
        return 3

def py_create():
    return PyNode()

def py_register(node):
    manager = pybemo.NodeRegistrySystem(node.nodeID())
    manager.addHeader("PyNode", "Some description", "icons/PyNode.png")
    manager.addPlug("path", pybemo.PlugDirection.Input, pybemo.PlugType.String, isRequired=False, isStrict=False)
    manager.addPlug("frame", pybemo.PlugDirection.Input, pybemo.PlugType.Int, isRequired=False, isStrict=False)
    manager.addPlug("output", pybemo.PlugDirection.Output, pybemo.PlugType.String, isRequired=False, isStrict=False)

def main():
    pybemo.init();

    pybemo.add("py", py_create, py_register)
    nodeA = pybemo.create("py")
    print "nodeA : nodeA=%s" % (nodeA)
    print "nodeA : execute=%s" % (nodeA.execute())
    print "nodeA : nodeID=%s" % (nodeA.nodeID())
    print "nodeA : typeID=%s" % (nodeA.typeID())
    print "nodeA : isValid=%s" % (nodeA.isValid())
    
    


    # py_nodeA = pybemo.create("py")
    # py_nodeB = pybemo.create("py")
    # py_nodeC = py_nodeA
    # print "py_nodeA : %s" % (py_nodeA)
    # print "py_nodeB : %s" % (py_nodeB)
    # print "py_nodeC : %s" % (py_nodeC)

    # ass_nodeA = pybemo.create("ass")
    # ass_nodeB = pybemo.create("ass")
    # ass_nodeC = ass_nodeA
    # print "ass_nodeA : %s" % (ass_nodeA)
    # print "ass_nodeB : %s" % (ass_nodeB)
    # print "ass_nodeC : %s" % (ass_nodeC)

    # cpp_nodeA = pybemo.create("cpp")
    # cpp_nodeB = pybemo.create("cpp")
    # cpp_nodeC = cpp_nodeB
    # print "cpp_nodeA : %s" % (cpp_nodeA)
    # print "cpp_nodeB : %s" % (cpp_nodeB)
    # print "cpp_nodeC : %s" % (cpp_nodeC)




    




if __name__ == '__main__':
    main()