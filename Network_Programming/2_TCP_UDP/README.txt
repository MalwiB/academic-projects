http://users.uj.edu.pl/~palacz/edu/201617-PS/index.html


2. Porównanie po³¹czeñ strumieniowych i datagramowych

Termin oddania finalnej wersji rozwi¹zania: 2017-04-03. Obowi¹zuje jêzyk C.
Zaimplementuj parê wspó³dzia³aj¹cych programów. Klient wysy³a porcje danych, serwer je odbiera, oba maj¹ w kodzie wstawione sztuczne opóŸnienia (sleep) pomiêdzy kolejnymi wywo³aniami funkcji write/read. Oba programy musz¹ wypisywaæ komunikaty sygnalizuj¹ce momenty, w których rozpoczyna i koñczy siê wykonywanie funkcji przesy³aj¹cych dane, oraz raportowaæ wyniki przez nie zwracane.
SprawdŸ eksperymentalnie co siê bêdzie dzia³o gdy pauzy w dzia³aniu serwera bêd¹ kilkukrotnie d³u¿sze ni¿ w kliencie, i co siê bêdzie dzia³o gdy sytuacja bêdzie odwrotna. Przetestuj równie¿ co siê dzieje gdy zmieniasz liczbê bajtów transferowanych jednym wywo³aniem write/read; sprawdŸ dzia³anie np. dla porcji danych rozmiaru 512 B, 16 KiB i 128 KiB (rozmiar zmieniaj niezale¿nie w kliencie i serwerze). Dla u³atwienia sobie eksperymentów mo¿esz, ale nie musisz, zaimplementowaæ specyfikowanie tych parametrów z linii komend.
Przerób programy tak aby korzysta³y z gniazdek UDP (zamiast write/read u¿yj sendto/recvfrom), powtórz eksperymenty.
Sporz¹dŸ w formie zwyk³ego pliku tekstowego notatkê podsumowuj¹c¹ Twoje obserwacje i do³¹cz j¹ do oddawanych programów.
Nieobowi¹zkowy problem dla zainteresowanych: czy i kiedy mo¿na u¿yæ read lub write z gniazdkiem UDP? A recvfrom i sendto z gniazdkiem TCP? I do czego mo¿na u¿yæ recv oraz send?