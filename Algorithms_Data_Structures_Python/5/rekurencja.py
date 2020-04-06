def factorial(n):
    suma = 1
    while n > 0:
        suma *= n
        n -= 1
    return suma


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