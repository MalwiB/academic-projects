--Autor:
Malwina Borysionek


--Data i miejsce:
19 marca 2015r.,Krakow


--Zawartość katalogu:
katalog zawiera 2 programy, wykonujace nastepujace czynnosci:
1)prosty program, wypisujacy UID, GID, PID, PPID, PGID procesu
2)program, który wypisuje UID, GID, PID, PPID, PGID procesów potomnych (fork w pętli) za pomocą programu 1, z wykorzystaniem funkcji exec


--Jak uruchomic programy:
Aby uruchomić program 2 najpierw należy skompilować programy 1 i 2, wpisując polecenie make albo make all, a nastepnie wprowadzić w konsoli "run2".
Dodatkową opcją jest możliwość utworzenia z plików archiwum za pomocą polecenia "make tar" oraz wyczyszczenia powstałych przy linkowaniu i  kompilowaniu programów plików obiektowych i wykonywalnych poprzez "make clean".
