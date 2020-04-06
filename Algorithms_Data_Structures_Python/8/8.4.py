from math import sqrt


def heron(a, b, c):
	if a + b < c or a + c < b or b + c < a:
		raise ValueError("Liczby nie spelniaja warunku trojkata")
	p = float((a + b + c)) / 2
	return sqrt(p * (p - a) * (p - b) * (p - c))


print "Pole trojkata o bokach dlugosci 1, 5, 5 wynosi: " + str(heron(1, 5, 5))
print "Pole trojkata o bokach dlugosci 1, 5, 5 wynosi: " + str(heron(8, 5, 5))
