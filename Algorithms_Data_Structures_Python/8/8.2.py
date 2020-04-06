import random
from math import sqrt


def odleglosc_srodek(x, y):
	return sqrt(x * x + y * y)


def calc_pi(n=100):
	liczba_kolo = 0
	liczba_calosci  = 0
	for i in range(0, n):
		x = random.random()
		y = random.random()
		if odleglosc_srodek(x, y) <= 1:
			liczba_kolo += 1
		liczba_calosci += 1
	return 4 * float(liczba_kolo) / liczba_calosci

pi = calc_pi(7000)
print "Przyblizenie liczby Pi obliczone przez program to " + str(pi) + "."
