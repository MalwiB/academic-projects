--Autor:
Malwina Borysionek


--Data i miejsce:
4 maja 2015r., Krakow


--Zawartość katalogu:
katalog zawiera:
1) program o nazwie 1.c- program, którego argumentami na wejscie są 1)nazwa programu-powielacza, 2)ilosc procesow, 3)liczba sekcji krytycznych, w programie najpierw tworzony jest semafor, inicjowany, a nastepnie procesy poprzez funkcję fork() (w execl uruchamiany program 2)
2) program, który jest otwierany przez pierwszy program, ma argumenty na wejscie: 1)nazwa programu, 2)ilosc procesow, 3)liczba sekcji krytycznych, wypisuje komunikaty dotyczace sekcji krytycznej
3) biblioteka funkcji do tworzenia, uzyskiwania dostępu, inicjowania, sterowania, operowania i usuwania semaforów

--Jak uruchomic programy:
Aby uruchomić program najpierw należy go skompilować, wpisując polecenie make albo make all, a nastepnie  uruchomić go poleceniem "make ARGS="tutaj należy wstawić wszystkie argumenty" run1, argumentami są 1)nazwa programu-powielacza, 2)ilosc procesow, 3)liczba sekcji krytycznych

przykład uruchomienia programu:
	make ARGS="2.x 3 4" run1


Dodatkową opcją jest możliwość utworzenia z plików archiwum za pomocą polecenia "make tar" oraz wyczyszczenia powstałych przy linkowaniu oraz kompilowaniu programów plików obiektowych i wykonywalnych poprzez "make clean".
