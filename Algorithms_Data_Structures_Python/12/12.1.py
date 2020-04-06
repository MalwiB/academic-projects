import random


def fill_list(n, k):
	L = []
	for i in range(0, n):
		L.append(random.randint(0, k-1))
	return L


def linear_search(y, L):
	L_W = []
	for index, item in enumerate(L):
		if item == y:
			L_W.append(index)
	return L_W


n = 80
k = 10
# fill_list(ilosc_liczb, zakres_wartosci)
L = fill_list(n, k)

y = random.randint(0, k-1)
print "Lista: ",
print L
L_W = linear_search(y, L)
print "Lista indeksow (liczone od 0) na ktorych wystapila liczba " + str(y) + ": ",
print L_W
print "Suma wystapien: " + str(len(L_W))
