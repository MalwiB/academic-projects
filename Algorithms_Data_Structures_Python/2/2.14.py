# 2.14
# najdluzszy wyraz w lini i jego dlugosc

def najdluzszy_wyraz(line):
	L = line.split()
	najdluzszy = ""
	for item in L:
		if len(item) > len(najdluzszy):
			najdluzszy = item
	return najdluzszy
	
	
line = "To jest jedna linia, najdluzszy wyraz"
najdluzszy = najdluzszy_wyraz(line)
print "Najdluzszy wyraz to: " + najdluzszy
print "Jego dlugosc wynosi: " + str(len(najdluzszy))