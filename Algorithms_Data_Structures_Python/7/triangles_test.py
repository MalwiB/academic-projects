import unittest
from triangles import Triangle
from points import Point


class TestTriangle(unittest.TestCase):

	def test_excep(self):
		self.assertRaises(ValueError, Triangle, 1, 2, 2, 4, 4, 8)
		self.assertRaises(ValueError, Triangle, 1, 2, 3, 6, 2, 4)

	def test_print(self):
		self.assertEqual(str(Triangle(1, 2, 3, 6, 0, 5)), "[(1, 2), (3, 6), (0, 5)]")
		self.assertEqual(str(Triangle(5, -2.5, 8.23, 7, -1, -3)), "[(5, -2.5), (8.23, 7), (-1, -3)]")
		self.assertEqual(repr(Triangle(2, -2, 5, 5, 1, 7)), "Triangle(2, -2, 5, 5, 1, 7)")

	def test_eq(self):
		self.assertTrue(Triangle(1, 2, 3, 6.7, 0.2, -4) == Triangle(1, 2, 3, 6.7, 0.2, -4))
		self.assertTrue(Triangle(1.5, 2, 3, 6.23, -1, -1) != Triangle(3, 6.23, -1, -1, 1.5, 2))
		self.assertTrue(Triangle(5, 1, 12, 9, 2, 5) != Triangle(5, 1, 9, 2, 0.87, 4))

	def test_center(self):
		self.assertEqual(Triangle(1, 2, 3, 6, 2, 8).center(), Point(2, 5))
		self.assertEqual(Triangle(-12, 3, 5, 9, 2, -3).center(), Point(- 2, 3))
		self.assertEqual(Triangle(-8, 2, 5, -8, 19, 2).center(), Point(16 / 3, - 4 / 3))

	def test_area(self):
		self.assertEqual(Triangle(1, 2, 3, 6, 2, 8).area(), 4)
		self.assertEqual(Triangle(-10, -3, 3, 7, 6, 1).area(), 54)
		self.assertEqual(Triangle(-12, 3, 5, 9, 2, -3).area(), 93)

	def test_move(self):
		self.assertEqual(Triangle(1, 2, 3, 6, -2, -8).move(3, -1), Triangle(4, 1, 6, 5, 1, -9))
		self.assertEqual(Triangle(-2, 3, 5, 9, 2, -3).move(1, 1), Triangle(-1, 4, 6, 10, 3, -2))

	def test_make3(self):
		self.assertEqual(Triangle(1, 2, 3, 6, 2, 8).make3(), [
			Triangle(1, 2, 3, 6, 2, 5),
			Triangle(3, 6, 2, 8, 2, 5),
			Triangle(1, 2, 2, 8, 2, 5)
		])
		self.assertEqual(Triangle(-12, 3, 5, 9, 2, -3).make3(), [
			Triangle(- 12, 3, 5, 9, -2, 3),
			Triangle(5, 9, 2, -3, -2, 3),
			Triangle(-12, 3, 2, -3, -2, 3)
		])
