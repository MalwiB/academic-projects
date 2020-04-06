def odwracanie(L, left, right):
	if left > right:
		return  -1
	else:
		for i in range((right - left + 1) /2):
			if left == right:
				return 0
			temp = L[left]
			print "Zamieniamy miejscami ",
			print L[left],
			print " i ",
			print L[right]
			L[left] = L[right]
			L[right] = temp
			left += 1
			right -= 1


sekwencja = [1, 2, 24, 56, 2, 3, 4, 17, 289, 297, 908, 1048]
print "Sekwencja przed odwroceniem: ",
print sekwencja
odwracanie(sekwencja, 0, 6)
print "\nSekwencja po odwroceniu: ",
print sekwencja