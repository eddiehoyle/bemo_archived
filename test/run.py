import sys
import unittest

sys.path.insert(0, "/Users/eddiehoyle/Code/cpp/bemo/build")
import pybemo



class TestNode(unittest.TestCase):

    def test_createFunc(self):
        pybemo.create_node("Bemo")

    def test_create(self):
        node = pybemo.Node("node")
        self.assertTrue(isinstance(node, pybemo.Node))

    def test_name(self):
        node = pybemo.Node("Penny")
        self.assertEqual(node.get_name(), "Penny")

    def test_setName(self):
        node = pybemo.Node("Penny")
        node.set_name("Bemo")
        self.assertEqual(node.get_name(), "Bemo")

class TestGraph(unittest.TestCase):

    def test_create(self):
        graph = pybemo.Graph()
        self.assertTrue(isinstance(graph, pybemo.Graph))

    def test_add(self):
        graph = pybemo.Graph()
        node = pybemo.Node("Bemo")
        graph.add(node)
        self.assertEqual(graph.get_count(), 1)



if __name__ == '__main__':
    unittest.main()