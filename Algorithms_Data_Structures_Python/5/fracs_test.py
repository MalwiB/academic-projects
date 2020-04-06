from fracs import *
import unittest


class TestFractions(unittest.TestCase):

    def setUp(self):
        self.zero = [0, 1]

    def test_add_frac(self):
        self.assertEqual(add_frac([1, 2], [1, 3]), [5, 6])
        self.assertEqual(add_frac([1, 4], [1, 4]), [1, 2])

    def test_sub_frac(self):
        self.assertEqual(sub_frac([3, 5], [1, 10]), [1, 2])

    def test_mul_frac(self):
        self.assertEqual(mul_frac([4, 7], [1, 2]), [2, 7])
        self.assertEqual(mul_frac([-1, 3], [1, 3]), [-1, 9])

    def test_div_frac(self):
        self.assertEqual(div_frac([4, 5], [1, 2]), [8, 5])

    def test_is_positive(self):
        self.assertTrue(is_positive([4, 5]))
        self.assertTrue(is_positive([-4, -5]))
        self.assertFalse(is_positive([-4, 5]))

    def test_is_zero(self):
        self.assertTrue(is_zero([0, -2]))
        self.assertTrue(is_zero([0, 5]))

    def test_cmp_frac(self):
        self.assertTrue(cmp_frac([3, 5], [1, 2]))
        self.assertEqual(cmp_frac([1, 2], [3, 2]), -1)
        self.assertEqual(cmp_frac([1, 2], [3, 6]), 0)

    def test_frac2float(self):
        self.assertEqual(frac2float([1, 2]), 0.5)
        self.assertEqual(frac2float([5, 2]), 2.5)
        self.assertEqual(frac2float([-15, 4]), -3.75)

    def tearDown(self): pass

if __name__ == '__main__':
    unittest.main()     # uruchamia wszystkie testy
