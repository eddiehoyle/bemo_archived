import pybemo

nodeA = pybemo.create("sum")
nodeA.setInput("valueA", 2)
nodeA.setInput("valueB", 3)

nodeB = pybemo.create("print")
nodeA.connect("result", nodeB, "message")

graphA = pybemo.create_graph("simple")
nodeA = pybemo.create_node("sum")
nodeB = pybemo.create_node("multiply")
graphA.add(nodeA)
graphA.add(nodeB)
graphA.connect("valueA", nodeA, "valueA")
graphA.connect("valueB", nodeA, "valueB")
nodeA.connect("result", nodeB, "valueA")
graphA.connect("valueB", nodeB, "valueB")
nodeB.connect("result", graphA, "result")
engine = pybemo.Engine(graphA)
engine.process(pybemo.Context.Local)

# A node is a process
# A graph is a collection of nodes (processes)

# Executing a graph:
# Doesn't really execute, just flattens node dependencies

# Executing a node:
# 1. Get inputs
# 2. Execute
# 3. Set outputs


nodeC = pybemo.create_node("multiply")
nodeC.set_input("valueA", 2)
nodeC.set_input("valueB", 3)
pybemo.Engine(nodeC).process(pybemo.Context.Local)


"""
graphA--nodeA--.
  |  |         |
  |  '-------nodeB--.
  |                 |
  '-----------------'--graphB
"""