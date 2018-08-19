import os
import sys
import unittest

TEST_DIRECTORY = os.path.abspath(os.path.dirname(__file__))
BEMO_DIRECTORY = os.path.join(TEST_DIRECTORY, "../../build")

sys.path.insert(0, BEMO_DIRECTORY)

if __name__ == '__main__':
    loader = unittest.TestLoader()
    tests = loader.discover(TEST_DIRECTORY)
    runner = unittest.runner.TextTestRunner()
    runner.run(tests)