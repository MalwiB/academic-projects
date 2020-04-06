--Autor: Malwina Borysionek

--Miejsca i data: Kraków, 2.04.2015r

--Zawartość katalogu:
3 programy: 
1) program obsługujący sygnały- można za jego pomocą wykonać operację domyślną, zignorować sygnał albo przejąć sygnał i włączyć własną jego obsługę
2) program uruchamiający program nr 1 w procesie potomnym i wysyłający do niego sygnał z procesu macierzystego za pomocą funkcji "kill"
3) program w którym zostaje stworzona grupa procesów, a następnie jest do niej wysyłany wybrany sygnał

--Uruchamianie programów:
1, 2, 3) Programy mają argumenty na wejście- pierwszy argument to nazwa programu, w tym przypadku należy wpisać "./1.x", "./2.x" lub "./3.x", w zależności, który program chcemy uruchomić, dalej numer wybranego przez nas sygnału sygnału, a później liczbę (1, 2 lub 3): 1- wykonuje operację domyślną, 2- ignoruje, 3- przechwytuje sygnał i obsługuje go

PRZYKŁAD uruchamiania jednego z programów:
	make
	./1.x 1 2

--Dodatkowe funkcje:
	-możliwość utworzenia z plików archiwum za pomocą polecenia "make tar"
	-czyszczenie powstałych przy linkowaniu oraz kompilowaniu programów plików obiektowych i wykonywalnych poprzez "make clean".
