
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
    system = pybemo.NodeSystem(node_id)
    system.addHeader("Some description", "icons/PyNode.png")
    system.addPlug("path", pybemo.PlugDirection.Input, pybemo.VariantType.String, isRequired=False, isStrict=False)
    # system.addPlug("frame", pybemo.PlugDirection.Input, pybemo.VariantType.Int, isRequired=False, isStrict=False)
    # system.addPlug("output", pybemo.PlugDirection.Output, pybemo.VariantType.String, isRequired=False, isStrict=False)

def bmo_registerPlugin(plugin_id):
    print "bmo_registerPlugin() : pluginID=%s" % (plugin_id)
    system = pybemo.PluginSystem(plugin_id)
    system.setHeader("PyPlugin", "Some description.", "icons/plugin32px.png")
    system.registerNode("py", py_create, py_layout)