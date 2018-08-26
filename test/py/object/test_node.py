
import unittest

import pybemo

class TestSumNode(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestSumNode, self).__init__(*args, **kwargs)
        self.nodeA = None

    def setUp(self):
        pybemo.initialise()
        self.nodeA = pybemo.create("sum")

    def tearDown(self):
        pybemo.terminate()
        self.nodeA = None

    # def test_create(self):
    #     self.assertIsNotNone(self.nodeA)
    #
    # def test_remove(self):
    #     pybemo.remove(self.nodeA)
    #     self.assertFalse(self.nodeA.isValid())
    #
    # def test_isValid(self):
    #     self.assertTrue(self.nodeA.isValid())
    #
    # def test_getID(self):
    #     self.assertNotEqual(self.nodeA.getID(), pybemo.ObjectID.invalid())
    #
    # def test_getType(self):
    #     self.assertEqual(self.nodeA.getType(), "sum")
    #
    # def test_getName(self):
    #     nodeB = pybemo.create("sum")
    #     nodeC = pybemo.create("sum", name="custom")
    #     self.assertEqual(self.nodeA.getName(), "sum0")
    #     self.assertEqual(nodeB.getName(), "sum1")
    #     self.assertEqual(nodeC.getName(), "custom")
    #
    # def test_setName(self):
    #     nodeB = pybemo.create("sum", name="customB")
    #     nodeC = pybemo.create("sum", name="customC")
    #     nodeB.setName("wizard")
    #     nodeC.setName("wizard")
    #     self.assertEqual(nodeB.getName(), "wizard")
    #     self.assertEqual(nodeC.getName(), "wizard0")
    #
    # def test_setInput_int(self):
    #     self.nodeA.setInput("valueA", 5)
    #     result = self.nodeA.getInput("valueA")
    #     self.assertEqual(result, 5)
    #
    # def test_setOutput_int(self):
    #     self.nodeA.setOutput("result", 5)
    #     result = self.nodeA.getOutput("result")
    #     self.assertEqual(result, 5)
    #
    def test_setInput_float(self):
        self.nodeA.setInput("valueA", 3.0)
        result = self.nodeA.getInput("valueA")
        self.assertIsInstance(result, long)
        self.assertEqual(result, 3)
    #
    # def test_setOutput_float(self):
    #     self.nodeA.setOutput("result", 3.0)
    #     result = self.nodeA.getOutput("result")
    #     self.assertIsInstance(result, int)
    #     self.assertEqual(result, 3)
    #
    # def test_execute(self):
    #     self.nodeA.setInput("valueA", 2)
    #     self.nodeA.setInput("valueB", 3)
    #     self.nodeA.execute()
    #     result = self.nodeA.getOutput("result")
    #     self.assertEqual(result, 5)

