
import unittest

import pybemo

class TestAPI(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestAPI, self).__init__(*args, **kwargs)

    def test_initialise(self):
        pybemo.initialise()

    def test_terminate(self):
        pybemo.terminate()

    def test_roundtrip(self):
        pybemo.initialise()
        pybemo.terminate()

    def test_initialise_doubleup(self):
        pybemo.initialise()
        pybemo.initialise()
        pybemo.initialise()

    def test_terminate_doubleup(self):
        pybemo.terminate()
        pybemo.terminate()
        pybemo.terminate()

    def test_roundtrip_doubleup(self):
        pybemo.initialise()
        pybemo.initialise()
        pybemo.terminate()
        pybemo.terminate()


class TestAPICreate(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestAPICreate, self).__init__(*args, **kwargs)

    def setUp(self):
        pybemo.initialise()

    def tearDown(self):
        pybemo.terminate()

    def test_create_py(self):
        node = pybemo.create("sum")
        self.assertTrue(node.valid())

    def test_create_cpp(self):
        node = pybemo.create("multiply")
        self.assertTrue(node.valid())

    def test_create_null(self):
        with self.assertRaises(TypeError):
            node = pybemo.create("butts")

    def test_exists(self):
        node = pybemo.create("multiply")
        self.assertTrue(pybemo.exists(node))


    # def test_uninitialisedFunc(self):
    #     with self.assertRaises(RuntimeError):
    #         pybemo.create("sum")
    #     with self.assertRaises(RuntimeError):
    #         pybemo.ls()
    #
    # def test_roundtripFunc(self):
    #     pybemo.initialise()
    #     pybemo.terminate()
    #     with self.assertRaises(RuntimeError):
    #         pybemo.create("sum")

