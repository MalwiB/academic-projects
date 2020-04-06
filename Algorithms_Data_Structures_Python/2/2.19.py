# 2.19
# dopelnianie liczb z listy do 3 cyfr


L = [7, 568, 42]
napis = ""
for element in L:
	if len(str(element)) != 3:
		kolejna = (str(element)).zfill(3)
	else:
		kolejna = str(element)
	napis = napis + kolejna
	
print napis