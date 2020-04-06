# 2.8
# Wykorzystac zbior do usuniecia duplikatow z listy

def usuwanie_duplikatow(L):
	Z = set(L)
	return list(Z)


L = {'a', 'b', 'b', 'b', 'c', 'd', 'a'}

L2 = usuwanie_duplikatow(L)
print L2