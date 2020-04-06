# 2.18
# znalezc liczbe cyfr 0 w duzej liczbie

# tutaj mamy 6 zer
cyfra = 53205807373060500
str_cyfra = str(cyfra)
L = list(str_cyfra)

liczba_wystapien = L.count('0')

print L
print "Liczba wystapien '0' w liczbie " + str_cyfra +":"
print liczba_wystapien