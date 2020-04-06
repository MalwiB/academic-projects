def solve1(a, b, c):
	if a == 0 and b == 0 and c == 0:
		print "Rozwiazaniem rownania dla wspolczynnikow a = " + str(a) + ", b = " + str(b) + ", c = " + str(c) + " jest kazda liczba "
	elif a == 0 and b == 0 and c != 0:
		print "Rownanie nie ma rozwiazan dla wspolczynnikow a = " + str(a) + ", b = " + str(b) + ", c = " + str(c)
	elif a == 0:
		print "Rozwiazaniem rownania dla wspolczynnikow a = " + str(a) + ", b = " + str(b) + ", c = " + str(c) + " jest prosta y = " + str(-float(c)/float(b))
	elif b == 0:
		print "Rozwiazaniem rownania dla wspolczynnikow a = " + str(a) + ", b = " + str(b) + ", c = " + str(c) + " jest prosta x = " + str(-float(c)/float(a))
	else:
		print "Rozwiazaniem rownania dla wspolczynnikow a = " + str(a) + ", b = " + str(b) + ", c = " + str(c) + " jest prosta y = " + str(float(-c)/float(b)) + "+(" + str(float(-a)/float(b)) + ")x"


solve1(0, 0, 3)
solve1(0, 798, 2)
solve1(1, 5, 0)
solve1(2, 1, 8)
solve1(-5, 20, 10)
solve1(-2, -0.5, 8.2)