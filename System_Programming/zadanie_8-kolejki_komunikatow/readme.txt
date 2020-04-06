--Autor:
Malwina Borysionek


--Data i miejsce:
25 maja 2015r., Krakow


--Zawartość katalogu:
katalog zawiera:
1) program o nazwie "klient", który wysyła ciąg znaków do kolejki komunikatów, a następnie odbiera z niej przetworzony tekst
2) program o nazwie "serwer" odbierający z kolejki teksty i zamieniający ich litery na wielkie, następnie odsyła komunikaty do kolejki
3) biblioteka kolejek komunikatow

--Jak uruchomic programy:
Aby uruchomić programy najpierw należy je skompilować, wpisując polecenie make albo make all, a nastepnie można je uruchomić np. poleceniem "make xterm", wtedy programy otworzą się każdy w osobnym terminalu.
Aby dodać wieksza liczbe klientow niz 2 nalezy powielic linijke w makefile "xterm -hold -title KLIENT -bg black -e ./$(EXEC2) &" i normalnie uruchomic "make xterm"

Dodatkową opcją jest możliwość utworzenia z plików archiwum za pomocą polecenia "make tar" oraz wyczyszczenia powstałych przy linkowaniu oraz kompilowaniu programów plików obiektowych i wykonywalnych poprzez "make clean".
