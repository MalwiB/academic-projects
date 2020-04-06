def flatten(sequence):
	new_seq = []
	for item in sequence:
		if isinstance(item, (list, tuple)):
			new_seq += flatten(item)
		else:
			new_seq.append(item)
	return new_seq


seq = [1,(2,3),[],[4,(5,6,7)],8,[9]]
print seq
print "\nPowyzsza sekwencja po splaszczeniu wyglada nastepujaco:"
print flatten(seq)