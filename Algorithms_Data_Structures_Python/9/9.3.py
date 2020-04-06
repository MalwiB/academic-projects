class Node:
	def __init__(self, data=None, next=None):
		self.data = data
		self.next = next

	def __str__(self):
		return str(self.data)


def find_max(head):
	if head is None:
		raise ValueError("Lista jest pusta!")
	element = head.data
	while head:
		if head.data > element:
			element = head.data
		head = head.next
	return element


def find_min(head):
	if head is None:
		raise ValueError("Lista jest pusta!")
	element = head.data
	while head:
		if head.data < element:
			element = head.data
		head = head.next
	return element

head = None
head = Node(7, head)
head = Node(3, head)
head = Node(199, head)
head = Node(4, head)
head = Node(1, head)
print "Lista: [1, 4, 199, 3, 7]"

print "\nNajwiekszym elementem w tablicy jest: " + str(find_max(head))
print "Najmniejszym elementem w tablicy jest: " + str(find_min(head))
