Opis programu:
W programie zaimplementowana jest metoda gradientow sprzezonych. Dla wyznaczonej macierzy podajemy proponowane przyblizenie rozwiazania rownania, a algorytm wyznacza rozwiazanie scisle. Jak widac, algorytm jest bardzo skuteczny dla takiej macierzy, bo nawet dla duzej rozbieznosci miedzy rozwiazaniami, znajduje rozwiazanie scisle w bardzo malej liczbie iteracji (2, 3...).

Kompilacja i uruchomienie:
Program nalezy kompilowac z flaga -lm, bo uzywa sie w nim biblioteki matematycznej.

gcc main.c -o prog -lm
./main