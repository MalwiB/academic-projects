class Node:
	def __init__(self, data=None, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right

	def __str__(self):
		return str(self.data)


def count_leafs(top):
	sum_l = 0
	if top is None:
		return 0
	if top.left is None and top.right is None:
		return 1
	sum_l += count_leafs(top.left)
	sum_l += count_leafs(top.right)
	return sum_l


def calc_total(top):
	total = 0
	if top is None:
		return 0
	if top.left is None and top.right is None:
		return top.data
	total += calc_total(top.left)
	total += top.data
	total += calc_total(top.right)
	return total



root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

print "Suma lisci w powyzszym drzewie wynosi: " + str(count_leafs(root)) + "."

print "Suma wartosci w lisciach powyzszego drzewa wynosi: " + str(calc_total(root)) + "."
