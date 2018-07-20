import pybemo as p
graph = p.Graph()

node = p.CustomNode()
graph.add(node)
graph.execute()

graph.output("path").connect(node.input("path"))

node0 = p.CustomNode()
node1 = p.CustomNode()
node2 = p.CustomNode()

group = p.Group()
group.add([node0, node1, node2])

group.getInputs()
# Result: [
#    <Plug(owner="node0", type="input", property="path")>,
#    <Plug(owner="node1", type="input", property="path")>,
#    <Plug(owner="node2", type="input", property="path")>,
#]

inputs0 = node0.getInputs()
# Result: {
#    "path": "",
#}
node0.getInput("path")
# Result: ""

# ---------------------------------------------------------------------------- #

# How do I create custom nodes?
# How does API know how to create custom node?

from pybemo import cmds
node = cmds.createNode("MyCustomNode")
