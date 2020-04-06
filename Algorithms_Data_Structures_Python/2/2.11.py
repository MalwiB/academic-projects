# 2.11
# wyswietlanie napisu word tak, aby jego znaki byly rodzielone znakiem podkreslenia

def podkreslenie(word):
	newword = ""
	i = 0
	while True:
		if word == "":
			break
		if i == (len(word) - 1):
			newword += word[i] 
			break
		newword += word[i] + '_'
		i = i + 1
	return newword


word = "dowolneslowo"
print podkreslenie(word)