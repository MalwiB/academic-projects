Krotki opis programu:
W programie znajdujemy rozwiazanie rownania opisanego macierza "macierz" z wyrazami wolnymi w wektorze 'wektor_wolnych'.
W tym celu najpierw wyznaczany jest rozklad Choleskiego macierzy (macierz=L*LT), a nastepnie znajdowane sa rozwiazania rownan L*wektor_Y=wektor_wolnych oraz LT*wektor_X=wektor_Y. 
wektor_X jest rozwiazaniem rownania.

Kompilacja i uruchomienie:
Program nalezy kompilowac z flaga -lm, poniewaz uzyte sa w nim funkcje z biblioteki matematycznej, np:
gcc main.c -o prog -lm
./prog