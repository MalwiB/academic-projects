# slownik tlumaczacy liczbe z systemu rzymskiego na arabski

# slownik-przelicznik
D = {"I" : 1, "V" : 5, "X" : 10, "L" : 50, "C" : 100, "D" : 500, "M" : 1000}

def roman2int(L):
	D2 = {}
	for i in L:
		liczba = i
		suma = 0
		for j in range(len(liczba)-1):
			#gdy liczba jest ostatnia
			if (j+1) == (len(liczba)-1):
					suma = suma + D[liczba[j+1]]
			#przypadek gdy pierwsza liczba wieksza od drugiej
			if porownaj_rzymskie(liczba[j], liczba[j+1]):
				suma = suma + D[liczba[j]]
			#gdy pierwsza liczba mniejsza od drugiej
			else:
				suma = suma -D[liczba[j]]
		D2[i] = suma
	return D2

	
def porownaj_rzymskie(l1, l2):
	if D[l1] >= D[l2]:
		return 1
	else:
		return 0
		


L = ["XIX", "XXVI", "IX", "XIV", "XXXVIII", "MXXV", "MM", "XCV"]

D_wynik = roman2int(L)

print D_wynik