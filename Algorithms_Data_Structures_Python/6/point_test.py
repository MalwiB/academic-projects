from points import *
from math import sqrt
import unittest


class TestPoint(unittest.TestCase):
	def test_print(self):
		self.assertEqual(str(Point(5, 2)), "(5, 2)")
		self.assertEqual(repr(Point(5, 2)), "Point(5, 2)")
		self.assertEqual(repr(Point(-5, -2)), "Point(-5, -2)")

	def test_eq(self):
		self.assertTrue(Point(2, 1) == (Point(2, 1)))
		self.assertTrue(Point(2, 1) != (Point(16, 8)))
		self.assertTrue(Point(-7, 8) != (Point(7, -8)))

	def test_add(self):
		self.assertEqual(Point(3, 4) + Point(7, 6), Point(10, 10))
		self.assertEqual(Point(-3, 4) + Point(7, -6), Point(4, -2))
		self.assertEqual(Point(10, 10) + Point(2, 2), Point(12, 12))

	def test_sub(self):
		self.assertEqual(Point(3, 4) - Point(7, 6), Point(-4, -2))
		self.assertEqual(Point(9, 8) - Point(1, 2), Point(8, 6))

	def test_mul(self):
		self.assertEqual(Point(3, 2) * Point(1, 8), Point(3, 16))
		self.assertEqual(Point(-6, 1) * Point(4, 5), Point(-24, 5))
		self.assertEqual(Point(-2, -1) * Point(-3, -3), Point(6, 3))

	def test_cross(self):
		self.assertEqual(Point(2, 7).cross(Point(8, 1)), -54)
		self.assertEqual(Point(-2, 1).cross(Point(3, 2)), -7)
		self.assertEqual(Point(3, 4).cross(Point(5, 1)), -17)

	def test_length(self):
		self.assertEqual(Point(1, 2).length(), sqrt(5))
		self.assertEqual(Point(2, 7).length(), sqrt(53))
		self.assertEqual(Point(-9, -1).length(), sqrt(82))

if __name__ == "__main__":
	unittest.main()  # wszystkie testy
