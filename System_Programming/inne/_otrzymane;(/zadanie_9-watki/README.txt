--Autor:
Malwina Borysionek


--Data i miejsce:
4 czerwca 2015r.,Krakow  /  20.08.2017r., Poznań


--Zawartość katalogu:
katalog zawiera program sharing_variable.c w ktorym zaimplementowany jest problem wzajemnego wykluczania watkow: proces uruchamia kilka watkow, wykonujacych nastepnie sekcje krytyczna, tylko jeden watek wykonuje w danej chwili swoja sekcje krytyczna, co jest zagwarantowane przez obecnosc muteksow, ktore blokuja i odblokowywuja dostep.


--Jak uruchomic programy:
Aby uruchomić program najpierw należy go skompilować, wpisując polecenie make albo make all, a nastepnie go uruchomic poleceniem "make run", ewentualnie wpisujac w terminalu "./sharing_variable.x".


Dodatkową opcją jest możliwość utworzenia z plików archiwum za pomocą polecenia "make tar" oraz wyczyszczenia powstałych przy linkowaniu oraz kompilowaniu programów plików obiektowych i wykonywalnych poprzez "make clean".
