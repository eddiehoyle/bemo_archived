
import unittest

import pybemo

class TestSumNode(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestSumNode, self).__init__(*args, **kwargs)
        self.nodeA = None
    #
    # def setUp(self):
    #     pybemo.initialise()
    #     self.nodeA = pybemo.create("sum")
    #
    # def tearDown(self):
    #     pybemo.terminate()
    #     pybemo.remove(self.nodeA)
    #     self.nodeA = None
    #
    # def test_create(self):
    #     self.assertIsNotNone(self.nodeA)
    #
    # def test_remove(self):
    #     self.assertTrue(self.nodeA.valid())
    #     pybemo.remove(self.nodeA)
    #     self.assertFalse(self.nodeA.valid())
    #
    # def test_valid(self):
    #     self.assertTrue(self.nodeA.valid())
    #
    # def test_id(self):
    #     self.assertNotEqual(self.nodeA.id(), pybemo.ObjectID.invalid())
    #
    # def test_type(self):
    #     self.assertEqual(self.nodeA.type(), "sum")
    #
    # def test_name(self):
    #     nodeB = pybemo.create("sum")
    #     nodeC = pybemo.create("sum", name="custom")
    #     self.assertEqual(self.nodeA.get_name(), "sum0")
    #     self.assertEqual(nodeB.get_name(), "sum1")
    #     self.assertEqual(nodeC.get_name(), "custom")
    #     pybemo.remove(nodeB)
    #     pybemo.remove(nodeC)
    #
    # def test_set_name(self):
    #     nodeB = pybemo.create("sum", name="customB")
    #     nodeC = pybemo.create("sum", name="customC")
    #     nodeB.set_name("wizard")
    #     nodeC.set_name("wizard")
    #     self.assertEqual(nodeB.get_name(), "wizard")
    #     self.assertEqual(nodeC.get_name(), "wizard0")
    #     pybemo.remove(nodeB)
    #     pybemo.remove(nodeC)
    #
    # def test_has_input(self):
    #     self.assertTrue(self.nodeA.has_input("valueA"))
    #     self.assertFalse(self.nodeA.has_input("butts"))
    #
    # def test_has_output(self):
    #     self.assertTrue(self.nodeA.has_output("result"))
    #     self.assertFalse(self.nodeA.has_output("butts"))
    #
    # def test_set_input_long(self):
    #     self.nodeA.set_input("valueA", 5)
    #     result = self.nodeA.get_input("valueA")
    #     self.assertIsInstance(result, long)
    #     self.assertEqual(result, 5)
    #
    # def test_set_output_long(self):
    #     self.nodeA.set_output("result", 5)
    #     result = self.nodeA.get_output("result")
    #     self.assertIsInstance(result, long)
    #     self.assertEqual(result, 5)
    #
    # def test_get_inputs(self):
    #     inputs = self.nodeA.get_inputs()
    #     self.assertNotEqual(len(inputs), 0)
    #     self.assertTrue("valueA" in inputs)
    #
    # def test_get_outputs(self):
    #     outputs = self.nodeA.get_outputs()
    #     self.assertNotEqual(len(outputs), 0)
    #     self.assertTrue("result" in outputs)
    #
    # @unittest.skip("Plug type policies not implemented yet.")
    # def test_set_input_float(self):
    #     self.nodeA.set_input("valueA", 3.0)
    #     result = self.nodeA.set_input("valueA")
    #     self.assertIsInstance(result, long)
    #     self.assertEqual(result, 3)
    #
    # @unittest.skip("Plug type policies not implemented yet.")
    # def test_set_output_float(self):
    #     self.nodeA.set_output("result", 3.0)
    #     result = self.nodeA.get_output("result")
    #     self.assertIsInstance(result, int)
    #     self.assertEqual(result, 3)
