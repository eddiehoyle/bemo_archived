import pybemo

nodeA = pybemo.create("sum")
nodeA.setInput("valueA", 2)
nodeA.setInput("valueB", 3)

nodeB = pybemo.create("print")
nodeA.connect("result", nodeB, "message")


graph = pybemo.create_graph("simple")
nodeA = graph.create_node("sum")
nodeB = graph.create_node("multiply")
engine = pybemo.Engine(graph)
engine.execute(pybemo.Context.Local)