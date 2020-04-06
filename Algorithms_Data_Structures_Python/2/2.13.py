# 2.13

	
def zlicz_litery(line):
	L = line.split()
	suma = sum([len(x) for x in L])
	return suma
	
#11
line = "to jest linia"
print zlicz_litery(line)