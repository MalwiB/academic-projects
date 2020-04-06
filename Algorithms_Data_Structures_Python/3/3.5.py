#program rysujacy miarke

def rysuj_miarke(liczba):
	miarka = ""
	for i in range(liczba*5+1):
		if not i%5:
			miarka = miarka + "|"
		else:
			miarka = miarka + "."
			
	miarka = miarka + "\n" + "0"
	
	for i in range(liczba):
		liczba_pustych = 5 - len(str(i+1))
		for j in range(liczba_pustych):
			miarka = miarka + " "
		miarka = miarka + str(i+1)
		
	print miarka
			
liczba = raw_input("Jak dluga ma byc miarka? ")
rysuj_miarke(int(liczba))