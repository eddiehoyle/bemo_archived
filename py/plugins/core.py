import pybemo

class PySimpleGraph(pybemo.BPyDagGraph):
    """"""

    def initialise(self):
        pass


def py_PySimpleGraphCreate():
    return PySimpleGraph()

def py_PySimpleGraphLayout(node_id):
    pass

class PySumNode(pybemo.BPyDagNode):
    """A node that computes the sum of two values, then sets an output result.
    Inputs:
        value_a (int): The first value.
        value_b (int): The second value.
    Outputs:
        result (int): The sum total of 'value_a' and 'value_b'.
    """

    def __init__(self):
        super(PySumNode, self).__init__()
        print "I'm here in Python!"

    def execute(self):
        value_a = self.getInput("valueA")
        value_b = self.getInput("valueB")
        self.setOutput("result", value_a + value_b)
        return 0

def py_PySumNodeCreate():
    return PySumNode()

def py_PySumNodeLayout(node_id):
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


class PyEvalNode(pybemo.BPyDagNode):
    """A node that computes the sum of two values, then sets an output result.
    Inputs:
        value_a (int): The first value.
        value_b (int): The second value.
    Outputs:
        result (int): The sum total of 'value_a' and 'value_b'.
    """

    def execute(self):
        snippet = self.getInput("snippet")
        eval(snippet)
        return 0

def py_PyEvalNodeCreate():
    return PyEvalNode()

def py_PyEvalNodeLayout(node_id):
    system = pybemo.NodeSystem(node_id)
    system.addHeader("Evaluate a Python snippet.", "icons/pyEvalNode16px.png")
    system.addPlug("snippet",
                   pybemo.PlugDirectionPolicy.Input,
                   pybemo.PlugAccessPolicy.Single,
                   pybemo.PlugCastPolicy.Anything,
                   pybemo.VariantType.String,
                   isRequired=True)


def bmo_registerPlugin(plugin_id):
    print "Registering plugin...", plugin_id
    # system = pybemo.PluginSystem(plugin_id)
    # system.setHeader("PyBemoNodes", "Core nodes.", "icons/bemocore_16px.png")
    # system.registerNode("sum", py_PySumNodeCreate, py_PySumNodeLayout)
    # system.registerGraph("simple", py_PySimpleGraphCreate, py_PySimpleGraphLayout)
    # system.registerNode("snippet", py_PyEvalNodeCreate, py_PyEvalNodeLayout)

    system = pybemo.PluginSystem(plugin_id)
    system.registerNode("sum", py_PySumNodeCreate)
    nodeA = system.create()
    print nodeA.isValid()