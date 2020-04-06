# 2.9
# funkcja, wykonujaca kopiowanie pliku, pomija linie zaczynajace sie od '#'

def kopiowanie_pliku(a_input, a_output):
	input = open(a_input, "r")
	output = open(a_output, "w")
	while input:
		text = input.readline()
		if(text == ""):
			break
		if text[0] != '#':
			output.write(text)
	input.close()
	output.close()
	
	
kopiowanie_pliku("2.8testIN.txt", "2.8testOUT.txt")