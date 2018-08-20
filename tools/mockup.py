import pybemo

nodeA = pybemo.create("sum")
nodeA.setInput("valueA", 2)
nodeA.setInput("valueB", 3)

nodeB = pybemo.create("print")
nodeA.connect("result", nodeB, "message")
