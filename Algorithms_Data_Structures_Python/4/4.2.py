def rysuj_miarke(liczba):
    miarka = ""
    for i in range(liczba * 5 + 1):
        if not i % 5:
            miarka += "|"
        else:
            miarka += "."
    miarka += "\n" + "0"
    for i in range(liczba):
        liczba_pustych = 5 - len(str(i + 1))
        for j in range(liczba_pustych):
            miarka += " "
        miarka += str(i + 1)

    print miarka


def rysuj_prostokat(szerokosc, dlugosc):
	prostokat = ""
	for i in range(int(szerokosc)):
		for j in range(int(dlugosc)):
			prostokat += "+---"
		prostokat += "+\n"
		for k in range(int(dlugosc)*4):
			if not k%4:
				prostokat += "|"
			else:
				prostokat += " "
		prostokat += "|"
		prostokat +="\n"
	for j in range(int(dlugosc)):
		prostokat += "+---"
	prostokat += "+\n"
	print prostokat


liczba = raw_input("Jak dluga ma byc miarka? ")
szerokosc = raw_input("Podaj szerokosc prostokata: ")
dlugosc = raw_input("Podaj dlugosc prostokata: ")
rysuj_miarke(int(liczba))
print "\n\n"
rysuj_prostokat(szerokosc, dlugosc)