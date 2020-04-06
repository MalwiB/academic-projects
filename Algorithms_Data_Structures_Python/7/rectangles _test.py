from rectangles import Rectangle
from points import Point
import unittest


class TestRectangle(unittest.TestCase):
	def test_print(self):
		self.assertEqual(str(Rectangle(1, 2, 3, 6)), "[(1, 2), (3, 6)]")
		self.assertEqual(str(Rectangle(5, -2.5, 8.23, 7)), "[(5, -2.5), (8.23, 7)]")
		self.assertEqual(repr(Rectangle(2, -2, 5, 5)), "Rectangle(2, -2, 5, 5)")

	def test_eq(self):
		self.assertTrue(Rectangle(1, 2, 3, 6.7) == Rectangle(1, 2, 3, 6.7))
		self.assertTrue(Rectangle(1.5, 2, 3, 6.23) != Rectangle(4, 1, 8, 9))
		self.assertTrue(Rectangle(5, 1, 12, 9) != Rectangle(5, 1, 9, 2))

	def test_center(self):
		self.assertEqual(Rectangle(1.5, 2, 5.5, 6).center(), Point(3.5, 4))
		self.assertEqual(Rectangle(-1, -1, 1, 1).center(), Point(0, 0))
		self.assertEqual(Rectangle(-2, -3, 1, 5).center(), Point(-0.5, 1))
		self.assertEqual(Rectangle(-9, 0.5, -5.5, 1).center(), Point(-7.25, 0.75))

	def test_area(self):
		self.assertEqual(Rectangle(1, 2, 5.2, 6).area(), 16.8)
		self.assertEqual(Rectangle(-1, 1, 7, 8).area(), 56)
		self.assertEqual(Rectangle(-2, -3.8, 1, 5).area(), 26.4)
		self.assertEqual(Rectangle(-9, 0.5, -5.5, 1).area(), 1.75)

	def test_move(self):
		self.assertEqual(Rectangle(1.5, 2, 5.5, 6).move(1.2, 7.45), Rectangle(2.7, 9.45, 6.7, 13.45))
		self.assertEqual(Rectangle(1, 2, 3, 4).move(2, 4), Rectangle(3, 6, 5, 8))
		self.assertEqual(Rectangle(-1.7, -2, -0.3, 4).move(-1, 2), Rectangle(-2.7, 0, -1.3, 6))

	def test_excep(self):
		self.assertRaises(ValueError, Rectangle, 2, 3, -2, -3)
		self.assertRaises(ValueError, Rectangle, 10, 20, 1, 2)

	def test_inters(self):
		# zawierajace sie w sobie
		self.assertEqual(Rectangle(-7, -2, 5, 5).intersection(Rectangle(1, 2, 3, 4)), Rectangle(1, 2, 3, 4))
		# nie przecinaja sie
		self.assertEqual(Rectangle(-5, -5, -2, -3).intersection(Rectangle(1, 4, 4, 6)), -1)
		# inne przypadki
		self.assertEqual(Rectangle(-2, -2, 3, 2).intersection(Rectangle(2, 1, 7, 5)), Rectangle(2, 1, 3, 2))
		self.assertEqual(Rectangle(2, 1, 7, 5).intersection(Rectangle(-2, -2, 3, 2)), Rectangle(2, 1, 3, 2))
		self.assertEqual(Rectangle(-1, 4, 4, 6).intersection(Rectangle(2, 1, 7, 5)), Rectangle(2, 4, 4, 5))
		self.assertEqual(Rectangle(2, 1, 7, 5).intersection(Rectangle(-1, 4, 4, 6)), Rectangle(2, 4, 4, 5))

	def test_cover(self):
		self.assertEqual(Rectangle(1, 1, 4, 4).cover(Rectangle(2, 2, 3, 3)), Rectangle(1, 1, 4, 4))
		self.assertEqual(Rectangle(2, 2, 3, 3).cover(Rectangle(1, 1, 4, 4)), Rectangle(1, 1, 4, 4))
		self.assertEqual(Rectangle(1, 1, 2, 2).cover(Rectangle(3, 4, 5, 6)), Rectangle(1, 1, 5, 6))
		self.assertEqual((Rectangle(3, 4, 5, 6)).cover(Rectangle(1, 1, 2, 2)), Rectangle(1, 1, 5, 6))
		self.assertEqual((Rectangle(1, 2, 3, 4)).cover(Rectangle(2, 1, 4, 3)), Rectangle(1, 1, 4, 4))
		self.assertEqual((Rectangle(2, 1, 4, 3)).cover(Rectangle(1, 2, 3, 4)), Rectangle(1, 1, 4, 4))
		self.assertEqual((Rectangle(-6, -2, -1, 1)).cover(Rectangle(2, -5, 6, -1)), Rectangle(-6, -5, 6, 1))

	def test_make4(self):
		self.assertEqual(Rectangle(1, 1, 5, 5).make4(), [
				Rectangle(1, 3, 3, 5),
				Rectangle(3, 3, 5, 5),
				Rectangle(1, 1, 3, 3),
				Rectangle(3, 1, 5, 3)])
		self.assertEqual(Rectangle(-1, -1, 5, 3).make4(), [
				Rectangle(-1, 1, 2, 3),
				Rectangle(2, 1, 5, 3),
				Rectangle(-1, -1, 2, 1),
				Rectangle(2, -1, 5, 1)
			])
