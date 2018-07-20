import pybemo

class AddNode(pybemo.Container):
    def execute(self):
        valueA = getInput("valueA")
        valueB = getInput("valueB")
        setOutput("result", valueA + valueB)