# 2.17
# posortowac wyrazy z line alfabetycznie
# -||- pod wzgledem dlugosci


line = "Remember, remember the fifth of November\nThe Gunpowder Treason and Plot"
L = line.split()
print "NIEPOSORTOWANE:"
print L
print '\n'

L.sort()
print "POSORTOWANE alfabetycznie:"
print L
print '\n'

L.sort(key=len)
print "POSORTOWANE wedlug dlugosci:"
print L
print '\n'