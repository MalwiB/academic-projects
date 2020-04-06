def odwracanie(L, left, right):
	if left == right:
		return  0
	elif left > right:
		return  -1
	else:
		temp = L[left]
		print "Zamieniamy miejscami ",
		print L[left],
		print " i ",
		print L[right]
		L[left] = L[right]
		L[right] = temp
		left += 1
		right -= 1
		odwracanie(L, left, right)


sekwencja = [1, 2, 24, 56, 2, 3, 4, 17, 289, 297, 908, 1048]
print "Sekwencja przed odwroceniem: ",
print sekwencja
odwracanie(sekwencja, 0, 7)
print "\nSekwencja po odwroceniu: ",
print sekwencja