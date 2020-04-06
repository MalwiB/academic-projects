from kolejka import *
import unittest


class TestStack(unittest.TestCase):
	def test_excep_przepelnienie(self):
		queue = Queue(3)
		queue.put(1)
		queue.put(2)
		queue.put(3)
		with self.assertRaises(PrzepelnienieKolejki):
			queue.put(4)

	def test_excep_pusta(self):
		queue = Queue(3)
		queue.put(1)
		queue.get()
		with self.assertRaises(PustaKolejka):
			queue.get()

	def test_get(self):
		queue = Queue(6)
		queue.put(5)
		queue.put(28)
		queue.put(1)
		queue.put(15)
		queue.put(8)
		self.assertEqual(queue.get(), 5)
		self.assertEqual(queue.get(), 28)

	def test_is_full(self):
		queue = Queue(5)
		queue.put(5)
		queue.put(28)
		queue.put(1)
		queue.put(15)
		queue.put(8)
		self.assertTrue(queue.is_full())

	def test_is_empty(self):
		queue = Queue(5)
		self.assertTrue(queue.is_empty())
		queue.put(5)
		self.assertFalse(queue.is_empty())


if __name__ == '__main__':
	unittest.main()