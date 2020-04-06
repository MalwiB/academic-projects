import os
from generator import *


def mergesort(L, left, right, i):
	if left < right:
		middle = (left + right) / 2
		mergesort(L, left, middle, i)
		mergesort(L, middle + 1, right, i)
		# przed scaleniem zapisujemy dane do pliku
		i += 1
		nazwa_pliku = "dane_przed_scaleniem.dat"
		f = open(nazwa_pliku, 'w')
		for item in L:
			f.write(str(L.index(item)) + " " + str(item) + "\n")
		f.close()
		merge(L, left, middle, right)



def merge(L, left, middle, right):
	T = [None] * (right - left + 1)
	left1 = left
	right1 = middle
	left2 = middle + 1
	right2 = right
	i = 0
	while left1 <= right1 and left2 <= right2:
		if L[left1] <= L[left2]:
			T[i] = L[left1]
			left1 += 1
		else:
			T[i] = L[left2]
			left2 += 1
		i += 1
	while left1 <= right1:
		T[i] = L[left1]
		left1 += 1
		i += 1
	while left2 <= right2:
		T[i] = L[left2]
		left2 += 1
		i += 1
	for i in range(right - left +1):
		L[left + i] = T[i]


L = random_without_repetition(35, 35)
print "Wygenerowana lista:"
print L
print "\n"

mergesort(L, 0, len(L)-1, 0)
print "Lista po posortowaniu:"
print L

nazwa_pliku = "dane_posortowane.dat"
f = open(nazwa_pliku, 'w')
for item in L:
	f.write(str(L.index(item)) + " " + str(item) + "\n")
f.close()
