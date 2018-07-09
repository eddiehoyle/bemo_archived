import sys
import unittest

sys.path.insert(0, "/Users/eddiehoyle/Code/cpp/bemo/build")
import pybemo

class TestFactoryNode(unittest.TestCase):

    def test_createFunc(self):
        node = pybemo.create_node("Bemo")
        self.assertEquals(node.get_name(), "Bemo")

    def test_readFunc(self):
        node = pybemo.create_node("Bemo")
        pybemo.read_node(node)

class TestNode(unittest.TestCase):

    def test_create(self):
        node = pybemo.Node("container")
        self.assertTrue(isinstance(node, pybemo.Node))

    def test_name(self):
        node = pybemo.Node("Penny")
        self.assertEqual(node.get_name(), "Penny")

    def test_setName(self):
        node = pybemo.Node("Penny")
        node.set_name("Bemo")
        self.assertEqual(node.get_name(), "Bemo")

    def test_execute(self):
        node = pybemo.Node("Penny")
        self.assertEquals(node.execute(), 0)

class TestGraph(unittest.TestCase):

    def test_create(self):
        graph = pybemo.Graph()
        self.assertTrue(isinstance(graph, pybemo.Graph))

    def test_add(self):
        graph = pybemo.Graph()
        node = pybemo.Node("Bemo")
        graph.add(node)
        self.assertEqual(graph.get_count(), 1)

    def test_remove(self):
        graph = pybemo.Graph()
        node = pybemo.Node("Bemo")
        graph.add(node)
        graph.remove(node)
        self.assertEqual(graph.get_count(), 0)

    def test_execute(self):
        graph = pybemo.Graph()
        node = pybemo.Node("Bemo")
        graph.add(node)
        self.assertEquals(graph.execute(), 0)



if __name__ == '__main__':
    unittest.main()