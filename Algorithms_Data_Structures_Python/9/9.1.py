class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

    def __str__(self):
        return str(self.data)


def remove_head(head):
    if head is None:
        raise ValueError("Lista jest pusta!")
    if head.next is None:
        return None, head.data
    return head.next, head.data


def next_to_last(head):
    while head.next.next:
        head = head.next
    return head


def remove_tail(head):
    if head is None:
        raise ValueError("Lista jest pusta!")
    if head.next is None:
        return None, head.data
    ntl = next_to_last(head)
    data = ntl.next.data
    ntl.next = None
    return head, data

head = None
head = Node(7, head)
head = Node(3, head)
head = Node(19, head)
head = Node(4, head)
head = Node(567, head)
# [567, 4, 19, 3, 7]

while head:
    head, data = remove_head(head)
    # head, data = remove_tail(head)
    print "Usuwam z listy element", str(data) + "."
