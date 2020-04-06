def factorial(n):
    suma = 1
    while n > 0:
        suma *= n
        n -= 1
    return suma


numer = raw_input("Podaj liczba z ktorej obliczona zostanie silnia: ")
print "wynosi ona: " + str(factorial(int(numer)))