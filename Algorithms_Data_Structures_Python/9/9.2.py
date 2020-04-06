class Node:
	def __init__(self, data=None, next=None):
		self.data = data
		self.next = next

	def __str__(self):
		return str(self.data)


def last_element(head):
	while head.next:
		head = head.next
	return head


def merge(head1, head2):
	if head1 is None and head2 is None:
		return None
	elif head1 is None:
		return head2
	elif head2 is None:
		return head1
	else:
		last_element(head1).next = head2
	return head1


# insert_head
head1 = None
head1 = Node(7, head1)
head1 = Node(3, head1)
head1 = Node(19, head1)
head1 = Node(4, head1)
head1 = Node(567, head1)
print "Lista pierwsza: [567, 4, 19, 3, 7]"

head2 = None
head2 = Node(1, head2)
head2 = Node(2, head2)
head2 = Node(3, head2)
head2 = Node(4, head2)
head2 = Node(5, head2)
head2 = Node(6, head2)
print "Lista druga: [6, 5, 4, 3, 2, 1]"

head3 = merge(head1, head2)

print "\nPolaczone listy: ",
while head3:
	print str(head3) + " ",
	head3 = head3.next
