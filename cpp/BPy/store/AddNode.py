import pybemo

class AddNode(pybemo.Node):
    def execute(self):
        valueA = getInput("valueA")
        valueB = getInput("valueB")
        setOutput("result", valueA + valueB)

def header():
    """Description, icons, etc"""
    return {"name": "MyCustomNode",
            "description": "My custom node!",
            "icon": "res/myCustomIcon.png"}

def layout():
    """Plugs, input/output, etc"""
    return [Plug("valueA", Plug.Direction.Input, Plug.Int),
            Plug("valueB", Plug.Direction.Input, Plug.Int),
            Plug("result", Plug.Direction.Output, Plug.Int),]

def create():
    """Creator function"""
    return MyCustomNode()
