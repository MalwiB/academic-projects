# sekwencja jest np. lista czy tez ciag znakow, krotka

def przeciecie_sekwencji(S1, S2):
	S3 = []
	for i in S1:
		if i in S2:
			S3.append(i)
	return S3
	
def suma_sekwencji(S1, S2):
	S3 = []
	# wszystkie elementy pierwszej sekwencji
	for i in S1:
		if i not in S3:
			S3.append(i)
	for i in S2:
		if i not in S1 and i not in S3:
			S3.append(i)
	return S3


S1 = [1, 2, 2, 3, 3, 4, 5, 6, 7]
S2 = [5, 6, 6, 7, 8, 836]

print "Przeciecie sekwencji: "
print przeciecie_sekwencji(S1, S2)
print "Suma sekwencji: "
print suma_sekwencji(S1, S2)