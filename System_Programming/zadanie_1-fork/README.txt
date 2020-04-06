--Autor:
Malwina Borysionek


--Data i miejsce:
18 marca 2015r.,Krakow


--Zawartość katalogu:
katalog zawiera 3 programy, wykonujace nastepujace czynnosci:
1) Wypisuje UID, GID, PID, PPID, PGID procesu
2) Wypisuje UID, GID, PID, PPID, PGID procesu macierzystego, a nastepnie procesow potomnych (fork uruchomiony w petli)
3) Wypisuje UID, GID, PID, PPID, PGID procesu macierzystego oraz procesów potomnych grupowanych pokoleniami od najstarszego do najmłodszego
oraz
4) Drzewo procesów dla programu 3, wraz z ich PID-ami i PPID-ami
5) Odpowiedź na pytanie, ile procesów powstaje w programie 3


--Jak uruchomic programy:
Aby uruchomić programy najpierw należy je skompilować, wpisując polecenie make albo make all, a nastepnie je włączyć poleceniem "make run1", "make run2", "make run3", zależnie od tego, który program chcemy uruchomić.
Dodatkową opcją jest możliwość utworzenia z plików archiwum za pomocą polecenia "make tar" oraz wyczyszczenia powstałych przy linkowaniu oraz kompilowaniu programów plików obiektowych i wykonywalnych poprzez "make clean".
