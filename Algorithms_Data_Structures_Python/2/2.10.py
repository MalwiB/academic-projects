# 2.10
# obliczanie liczby wyrazow w napisie (wyrazy oddzielone: spacja, tab, newline)



def ile_wyrazow(line):
	suma = 1
	for char in line:
		if(char == ' ' or char == '\n' or char == '\t'):
			suma = suma + 1
	return suma
	

# 10 wyrazow
line = "zal.pl spacja\ndalej\nnastepna linijka\ta tu tabulator... nowy wyraz"
print ile_wyrazow(line)


# !!! da sie tez LISTA