def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        suma = 0
        poprzedni = 0
        kolejny = 1
        for i in range(n+1):
            suma += poprzedni
            poprzedni = kolejny
            kolejny = suma
        return suma

n = int(raw_input("Podaj numer wyrazu w ciagu Fibonacciego: "))
print "Wartosc tego wyrazu to: " + str(fibonacci(n))