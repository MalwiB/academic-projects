http://users.uj.edu.pl/~palacz/edu/201617-PS/index.html


2. Por�wnanie po��cze� strumieniowych i datagramowych

Termin oddania finalnej wersji rozwi�zania: 2017-04-03. Obowi�zuje j�zyk C.
Zaimplementuj par� wsp�dzia�aj�cych program�w. Klient wysy�a porcje danych, serwer je odbiera, oba maj� w kodzie wstawione sztuczne op�nienia (sleep) pomi�dzy kolejnymi wywo�aniami funkcji write/read. Oba programy musz� wypisywa� komunikaty sygnalizuj�ce momenty, w kt�rych rozpoczyna i ko�czy si� wykonywanie funkcji przesy�aj�cych dane, oraz raportowa� wyniki przez nie zwracane.
Sprawd� eksperymentalnie co si� b�dzie dzia�o gdy pauzy w dzia�aniu serwera b�d� kilkukrotnie d�u�sze ni� w kliencie, i co si� b�dzie dzia�o gdy sytuacja b�dzie odwrotna. Przetestuj r�wnie� co si� dzieje gdy zmieniasz liczb� bajt�w transferowanych jednym wywo�aniem write/read; sprawd� dzia�anie np. dla porcji danych rozmiaru 512 B, 16 KiB i 128 KiB (rozmiar zmieniaj niezale�nie w kliencie i serwerze). Dla u�atwienia sobie eksperyment�w mo�esz, ale nie musisz, zaimplementowa� specyfikowanie tych parametr�w z linii komend.
Przer�b programy tak aby korzysta�y z gniazdek UDP (zamiast write/read u�yj sendto/recvfrom), powt�rz eksperymenty.
Sporz�d� w formie zwyk�ego pliku tekstowego notatk� podsumowuj�c� Twoje obserwacje i do��cz j� do oddawanych program�w.
Nieobowi�zkowy problem dla zainteresowanych: czy i kiedy mo�na u�y� read lub write z gniazdkiem UDP? A recvfrom i sendto z gniazdkiem TCP? I do czego mo�na u�y� recv oraz send?