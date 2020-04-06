import random
from math import sqrt
from modified_quicksort import modified_quicksort


# n - ilosc liczb, k - zakres
def random_without_repetition(n, k):
	L = random.sample(range(k), n)
	return L


def random_almost_sorted(n, k):
	L = random_without_repetition(n, k)
	modified_quicksort(L, 0, len(L)-1)
	return L


def random_almost_sorted_reverse(n, k):
	L = random_almost_sorted(n, k)
	L.reverse()
	return L


def random_gauss(n, mu, sigma):
	L = []
	for i in range(n):
		# gauss(mean, standard_deviation)
		L.append(int(random.gauss(mu, sigma)))
	return L


def random_with_repetition(n):
	L = []
	k = int(sqrt(n))
	for i in range(n):
		L.append(random.randrange(k))
	return L
