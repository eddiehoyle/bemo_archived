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
    system.addHeader("Add two values together.", "icons/SumNode.png")
    system.addPlug("valueA",
                   pybemo.PlugDirectionPolicy.Input,
                   pybemo.PlugAccessPolicy.Single,
                   pybemo.PlugCastPolicy.Anything,
                   pybemo.VariantType.Long,
                   isRequired=True)
    system.addPlug("valueB",
                   pybemo.PlugDirectionPolicy.Input,
                   pybemo.PlugAccessPolicy.Single,
                   pybemo.PlugCastPolicy.Anything,
                   pybemo.VariantType.Long,
                   isRequired=True)
    system.addPlug("result",
                   pybemo.PlugDirectionPolicy.Output,
                   pybemo.PlugAccessPolicy.Single,
                   pybemo.PlugCastPolicy.Anything,
                   pybemo.VariantType.Long,
                   isRequired=True)

def bmo_registerPlugin(plugin_id):
    system = pybemo.PluginSystem(plugin_id)
    system.setHeader("PyBemoNodes", "Core nodes.", "icons/bemocore_16px.png")
    system.registerNode("sum", py_create, py_layout)