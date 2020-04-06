def P(i, j):
	# D[(i, j)]
	D = {}
	D[(0, 0)] = 0.5
	for x in range(1, i+1):
		D[(x, 0)] = 0.0
	for x in range(1, j+1):
		D[(0, x)] = 1.0
	if i == 0 and j == 0:
		return 0.5
	elif j == 0 and i > 0:
		return 0.0
	elif i == 0 and j > 0:
		return 1.0
	elif i > 0 and j > 0:
		for i in range(1, i+1):
			for j in range(1, j+1):
				D[(i, j)] = 0.5 * (D[(i-1, j)] + D[(i, j-1)])
	return D[(i, j)]


print "P(0, 0) = " + str(P(0, 0))
print "P(4, 0) = " + str(P(4, 0))
print "P(0, 4) = " + str(P(0, 4))
print "P(4, 4) = " + str(P(4, 4))
print "P(10, 7) = " + str(P(10, 7))
print "P(16, 13) = " + str(P(16, 13))
