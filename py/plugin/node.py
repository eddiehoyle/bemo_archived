import pybemo

class PySumNode(pybemo.AbstractNode):
    """A node that computes the sum of two values, then sets an output result.
    Inputs:
        value_a (int): The first value.
        value_b (int): The second value.
    Outputs:
        result (int): The sum total of 'value_a' and 'value_b'.
    """

    def execute(self):
        value_a = self.getInput("valueA")
        value_b = self.getInput("valueB")
        self.setOutput("result", value_a + value_b)
        return 0

def py_create():
    return PySumNode()

def py_layout(node_id):
    system = pybemo.NodeSystem(node_id)
    system.addHeader("Add two values together.", "icons/PyNode.png")
    system.addPlug("valueA", pybemo.PlugDirection.Input,  pybemo.VariantType.Int, isRequired=True, isStrict=True)
    system.addPlug("valueB", pybemo.PlugDirection.Input,  pybemo.VariantType.Int, isRequired=True, isStrict=True)
    system.addPlug("result", pybemo.PlugDirection.Output, pybemo.VariantType.Int)

def bmo_registerPlugin(plugin_id):
    system = pybemo.PluginSystem(plugin_id)
    system.setHeader("PyBemoNodes", "Core nodes.", "icons/bemocore_16px.png")
    system.registerNode("sum", py_create, py_layout)