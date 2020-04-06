from stos import *
import unittest


class TestStack(unittest.TestCase):

    def test_excep_przepelnienie(self):
        stos = Stack(3)
        stos.push(1)
        stos.push(1)
        stos.push(1)
        with self.assertRaises(PrzepelnienieStosu):
            stos.push(1)

    def test_excep_pusty(self):
        stos = Stack(6)
        stos.push(1)
        stos.pop()
        with self.assertRaises(PustyStos):
            stos.pop()

    def test_pop(self):
        stos = Stack(6)
        stos.push(8)
        self.assertEqual(stos.pop(), 8)

    def test_is_full(self):
        stos = Stack(3)
        stos.push(15)
        stos.push(2)
        stos.push(90)
        self.assertTrue(stos.is_full())
        stos.pop()
        self.assertFalse(stos.is_full())

    def test_is_empty(self):
        stos = Stack(3)
        self.assertTrue(stos.is_empty())
        stos.push(56)
        self.assertFalse(stos.is_empty())

if __name__ == '__main__':
    unittest.main()
