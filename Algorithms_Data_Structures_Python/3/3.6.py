# program rysujacy prostokat z kratek

def rysuj_prostokat(szerokosc, dlugosc):
	prostokat = ""
	for i in range(int(szerokosc)):
		for j in range(int(dlugosc)):
			prostokat = prostokat + "+---"
		prostokat = prostokat + "+" + "\n"
		for k in range(int(dlugosc)*4):
			if not k%4:
				prostokat = prostokat + "|"
			else:
				prostokat = prostokat + " "
		prostokat = prostokat + "|"
		prostokat = prostokat + "\n"
	for j in range(int(dlugosc)):
		prostokat = prostokat + "+---"
	prostokat = prostokat + "+" + "\n"
	print prostokat		

szerokosc = raw_input("Podaj szerokosc prostokata: ")
dlugosc = raw_input("Podaj dlugosc prostokata: ")
rysuj_prostokat(szerokosc, dlugosc)