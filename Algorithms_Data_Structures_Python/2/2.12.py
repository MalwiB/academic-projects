# 2.12
# 1) napis zlozony z pierwszych znakow wyrazow z wiersza line
# 2) -||- ostatnich


def pierwsze_znaki(line):
	wyraz = ""
	L = line.split()
	print L
	for item in L:
		wyraz = wyraz + item[0].lower()
	return wyraz
	
def ostatnie_znaki(line):
	wyraz = ""
	L = line.split()
	print L
	for item in L:	
		indeks = len(item)-1
		while not item[indeks].isalnum():
				indeks = indeks - 1
		wyraz = wyraz + item[indeks].lower()
	return wyraz
	
	
# wyraz, ktory powstaje przez funkcje pierwsze_znaki() to: tjwzkwuwmbdl
line = "To jest wiersz, z ktorego wyrazow utworzymy wyraz, Moga Byc duze Litery"
print pierwsze_znaki(line)

# ostatnie_znaki, powstaje: otzzoyzacey
print ostatnie_znaki(line)


