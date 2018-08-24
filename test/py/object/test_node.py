
import unittest

import pybemo

class TestNode(unittest.TestCase):

    def setUp(self):
        pybemo.initialise()

    def tearDown(self):
        pybemo.terminate()

    # def test(self):
    #     self.assertEqual(1, 1)
    #
    # def test_create(self):
    #     node = pybemo.create("py")
    #     self.assertIsNotNone(node)
    #
    # def test_getID(self):
    #     node = pybemo.create("py")
    #     self.assertNotEqual(node, pybemo.ObjectID())
    #
    # def test_getType(self):
    #     node = pybemo.create("py")
    #     self.assertEqual(node.getType(), "py")
    #
    # def test_getName(self):
    #     nodeA = pybemo.create("py")
    #     nodeB = pybemo.create("py")
    #     self.assertEqual(nodeA.getName(), "py0")
    #     self.assertEqual(nodeB.getName(), "py1")
    #     nodeC = pybemo.create("py", name="custom")
    #     self.assertEqual(nodeC.getName(), "custom")
    #
    # def test_setName(self):
    #     node = pybemo.create("py", name="customA")
    #     self.assertEqual(node.getName(), "customA")
    #     node.setName("customB")
    #     self.assertEqual(node.getName(), "customB")
    #
    # def test_isValid(self):
    #     node = pybemo.create("py")
    #     self.assertTrue(node.isValid())
    #     pybemo.remove(node)
    #     self.assertFalse(node.isValid())
    #
    # def test_setInput_int(self):
    #     node = pybemo.create("py")
    #     node.setInput("test", 10)

    def test_setInput_int(self):
        node = pybemo.create("py")
        node.setInput("test", 10)

    def test_setInput_float(self):
        node = pybemo.create("py")
        node.setInput("test", 4.32)

    def test_setInput_str(self):
        node = pybemo.create("py")
        node.setInput("test", "value")

    def test_setInput_unknown(self):
        node = pybemo.create("py")
        node.setInput("test", None)


