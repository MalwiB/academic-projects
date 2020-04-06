from random import randint


class RandomQueue:
	def __init__(self):
		self.items = []

	def __str__(self):
		return str(self.items)

	def is_empty(self):
		return not self.items

	def is_full(self):
		return False

	def insert(self, element):
		self.items.append(element)

	def remove(self):
		index = randint(0, len(self.items)-1)
		element = self.items[index]
		self.items[index] = self.items[len(self.items)-1]
		self.items.pop()
		return element


random_queue = RandomQueue()
random_queue.insert(1)
random_queue.insert(2)
random_queue.insert(3)
random_queue.insert(4)
random_queue.insert(5)
random_queue.insert(6)
random_queue.insert(7)
random_queue.insert(8)
random_queue.insert(9)
random_queue.insert(10)

print "Usuwanie losowego elementu ", random_queue.remove()
print "Aktualny stan kolejki: ", str(random_queue)

print "Usuwanie losowego elementu ", random_queue.remove()
print "Aktualny stan kolejki: ", str(random_queue)

print "Usuwanie losowego elementu ", random_queue.remove()
print "Aktualny stan kolejki: ", str(random_queue)
