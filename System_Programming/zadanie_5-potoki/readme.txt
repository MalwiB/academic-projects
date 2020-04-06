--Autor:
Malwina Borysionek


--Data i miejsce:
19 kwietnia 2015r., Krakow


--Zawartość katalogu:
katalog zawiera:
1) program o nazwie "producent"- tworzy potok nazwany o nazwie wprowadzonej przez użytkownika i wysyła zawartość pliku wybranego przez użytkownika do programu o nazwie "klient"
2) program "klient"- program odbierający z potoku nazwanego o nazwie wprowadzonej przez użytkownika dane, zapisuje je następnie do pliku o nazwie także wprowadzonej przez użytkownika
3) "program", który tworzy potok FIFO, uruchamia oba podane wyżej programy w procesach potomnych, z parametrami podanymi wcześniej przez użytkownika, program ma na celu przesłanie przez potok FIFO danych z jednego pliku do drugiego, między dwoma niezależnymi procesami


--Jak uruchomic programy:
Aby uruchomić program najpierw należy go skompilować, wpisując polecenie make albo make all, a nastepnie  uruchomić go poleceniem "make ARGS="tutaj należy wstawić wszystkie argumenty" run1, argumentami są 1)nazwa potoku, 2)nazwa procesu producenta, 3)nazwa procesu klienta,
4)plik z którego czytamy, 5)plik do którego zapisujemy

przykład uruchomienia programu:
make ARGS="potok producent.x klient.x plik.txt plik2.txt" run1


Dodatkową opcją jest możliwość utworzenia z plików archiwum za pomocą polecenia "make tar" oraz wyczyszczenia powstałych przy linkowaniu oraz kompilowaniu programów plików obiektowych i wykonywalnych poprzez "make clean".
