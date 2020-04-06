def sum_seq(sequence):
	suma = 0
	for item in sequence:
		if isinstance(item, (list, tuple)):
			suma += sum_seq(item)
		else:
			suma += item
	return suma


seq = [ [1,2,3,4], 1, 2, [6, 7], 1, [1, [6, 2, 3], (2, 3, 4)]]
print seq
print "\nSuma liczb w powyzszej sekwencji zagniezdzonej wynosi",
print sum_seq(seq)