import random


def fill_list(n, k):
	L = []
	for i in range(0, n):
		L.append(random.randint(0, k-1))
	return L


def binary_rek(L, left, right, y):
	while left <= right:
		center = (right + left) / 2
		if y == L[center]:
			return center
		elif y > L[center]:
			return binary_rek(L, center+1, right, y)
		elif y < L[center]:
			return binary_rek(L, left, center-1, y)
	return None


# wypelnienie listy 20 randomowymi wartosciami z przedzialu (0, 99)
elementy = 20
L = fill_list(elementy, 50)
print "Nieposortowana lista: ",
print L
print "Posortowana lista: ",
L.sort()
print L

element = 23
pozycja = binary_rek(L, 0, elementy-1, element)
if pozycja is None:
	print "Nie znaleziono elementu " + str(element) + " w liscie."
else:
	print "\nZnaleziono element " + str(element) + " na pozycji " + str(pozycja) + " (liczac od 0).\n"