# znalezc liste zawierajaca sumy liczb z sekwencji

def znajdz_liste_sum(L):
	S = []
	for seq in L:
		suma = 0
		for item in seq:
			suma = suma + item
		S.append(suma)
	return S

	
L = [[],[4],(1,2),[3,4],(5,6,7)]
S = znajdz_liste_sum(L)

print S