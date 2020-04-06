Opis programu:
Program wylicza przyblizone rozwiazanie rownania podanego w zadaniu z uzyciem wzoru Shermana-Morrisona.
W tym celu najpierw znajduje rozklad Choleskiego zadanej macierzy, a nastepnie rozwiazuje (niewielkiem kosztem) rownania, dzieki ktorym uzyskujemy wektory Z i Q. Nastepnie tylko wykonujemy wzor i otrzymujemy szukany wektor przyblizonego rozwiazania. Jest to na tyle dokladny wynik na ile pozwala zakres double oraz uzyte algorytmy.

Kompilacja i uruchomienie:
gcc main.c -o main -lm
./main