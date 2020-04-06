from generator import *

# n liczb z zakresu od 0 do k
L = random_without_repetition(10, 10)
print "random_without_repetition(): " + str(L) + "\n"

L = random_almost_sorted(20, 30)
print "random_almost_sorted(): " + str(L) + "\n"

L = random_almost_sorted_reverse(20, 30)
print "random_almost_sorted_reverse(): " + str(L) + "\n"

L = random_gauss(30, 0, 3)
print "random_gauss(): " + str(L) + "\n"

L = random_with_repetition(25)
print "random_with_repetition(): " + str(L) + "\n"
