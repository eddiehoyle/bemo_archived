import pybemo

class PrintNode(pybemo.Container):
    def execute(self):
        message = getInput("message")
        formatted = "[PrintNode] : Message : {0}".format(message)
        print >> sys.stdout, formatted
