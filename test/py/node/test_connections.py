
import unittest

import pybemo

class TestConnections(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestConnections, self).__init__(*args, **kwargs)
        self.nodeA = None
        self.nodeB = None
        self.nodeC = None

    def setUp(self):
        pybemo.initialise()
        self.nodeA = pybemo.create("sum")
        self.nodeB = pybemo.create("sum")
        self.nodeC = pybemo.create("sum")

    def tearDown(self):
        # pybemo.remove(self.nodeA) # Fix this
        # pybemo.remove(self.nodeB) # Fix this
        # pybemo.remove(self.nodeC) # Fix this
        pybemo.terminate()

    @unittest.skip("Create a simple connection.")
    def test_connect(self):
        self.nodeA.connect("result", self.nodeB, "valueA")
        self.assertTrue(True)

    @unittest.skip("Disconnect a specific connection.")
    def test_disconnect(self):
        self.nodeA.connect("result", self.nodeB, "valueA")
        self.nodeA.connect("result", self.nodeC, "valueA")
        self.nodeA.disconnect("result", self.nodeB, "valueA")

    @unittest.skip("Test disconnecting all connections from a plug.")
    def test_disconnectAll(self):
        self.nodeA.connect("result", self.nodeB, "valueA")
        self.nodeA.connect("result", self.nodeC, "valueA")
        self.nodeA.disconnect("result")