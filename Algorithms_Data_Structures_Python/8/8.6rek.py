def P(i, j):
	if i == 0 and j == 0:
		return 0.5
	elif j == 0 and i > 0:
		return 0.0
	elif i == 0 and j > 0:
		return 1.0
	elif i > 0 and j > 0:
		return 0.5 * (P(i-1, j) + P(i, j-1))


print "P(0, 0) = " + str(P(0, 0))
print "P(4, 0) = " + str(P(4, 0))
print "P(0, 4) = " + str(P(0, 4))
print "P(4, 4) = " + str(P(4, 4))
print "P(10, 7) = " + str(P(10, 7))
print "P(16, 13) = " + str(P(16, 13))
# przy wiekszych wartosciach ekurencyjna wersja dziala wolno