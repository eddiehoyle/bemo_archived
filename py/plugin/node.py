
import pybemo

class PyNode(pybemo.AbstractNode):
    def execute(self):
        print "Executing %s!" % (self.__class__.__name__)
        return 3

def py_create():
    print "py_create()"
    return PyNode()

def py_layout(node_id):
    print "py_layout() : node_id=%s" % (node_id)
    manager = pybemo.NodeRegistrySystem(node_id)
    manager.addHeader("PyNode", "Some description", "icons/PyNode.png")
    manager.addPlug("path", pybemo.PlugDirection.Input, pybemo.PlugType.String, isRequired=False, isStrict=False)
    manager.addPlug("frame", pybemo.PlugDirection.Input, pybemo.PlugType.Int, isRequired=False, isStrict=False)
    manager.addPlug("output", pybemo.PlugDirection.Output, pybemo.PlugType.String, isRequired=False, isStrict=False)

def bmo_registerPlugin(pluginID):
    print "bmo_registerPlugin() : pluginID=%s" % (pluginID)
    system = pybemo.PluginSystem(pluginID)
    system.setHeader("PyPlugin", "Some description.")
    system.registerNode("PyNode", py_create, py_layout)