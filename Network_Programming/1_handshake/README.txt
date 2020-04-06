http://users.uj.edu.pl/~palacz/edu/201617-PS/index.html


1. Wizyt�wki serwer�w

Termin oddania finalnej wersji rozwi�zania: 2017-03-20. Obowi�zuje j�zyk C.
Wiele protoko��w sieciowych korzysta z czego� w rodzaju wizyt�wki: po nawi�zaniu po��czenia mi�dzy klientem a serwerem serwer, nie czekaj�c na �adne dane od klienta, wysy�a lini� tekstu. Przez �lini� tekstu� nale�y rozumie� ci�g drukowalnych znak�w ASCII zako�czony dwuznakiem \r\n (cho� czasem linia zako�czona jest tylko znakiem \n). Informacje zawarte w tej linii przewa�nie pozwalaj� klientowi zorientowa� si� kt�r� wersj� protoko�u obs�uguje serwer, jakie oprogramowanie dzia�a na serwerze, itp.
Napisz program-klienta, kt�ry b�dzie ��czy� si� (u�yj socket i connect) z us�ug� wskazan� argumentami podanymi w linii komend (adres IPv4 w argv[1], numer portu TCP w argv[2]), drukowa� na ekranie wizyt�wk� zwr�con� przez serwer, i zamyka� po��czenie. Pami�taj o zasadzie ograniczonego zaufania i weryfikuj czy odebrane bajty to na pewno drukowalne znaki zanim je prze�lesz na stdout.
Przetestuj program ��cz�c si� z nast�puj�cymi us�ugami:

149.156.43.64 22 (us�uga SSH)
149.156.89.147 25 (us�uga SMTP)
193.219.28.2 21 (us�uga FTP)
193.219.28.2 873 (us�uga rsync)
149.156.225.215 80 (us�uga HTTP)

W tym ostatnim przypadku klient powinien si� zawiesi�, bo serwery HTTP nie wysy�aj� wizyt�wek. Trzeba b�dzie r�cznie przerwa� jego niesko�czone oczekiwanie naciskaj�c kombinacj� klawiszy Ctrl-C.

Uwaga: nie pr�buj testowa� klienta uruchamiaj�c go na serwerze spk-ssh.if.uj.edu.pl, bo nie zadzia�a. Ten serwer dost�powy dla bezpiecze�stwa jest obwarowany firewallami blokuj�cymi pr�by otwierania po��cze� wychodz�cych do wi�kszo�ci us�ug (z powy�szej listy przepuszcza tylko HTTP).
Napisz drugi program, kt�ry b�dzie atrap� serwera. Powinien stworzy� sobie gniazdko TCP nas�uchuj�ce na porcie o numerze podanym jako argv[1] (u�yj socket, bind i listen), nast�pnie w p�tli czeka� na przychodz�ce po��czenia (accept), wysy�a� ci�g "Hello, world!\r\n" jako swoj� wizyt�wk�, zamyka� odebrane po��czenie, i wraca� na pocz�tek p�tli. Program nie ko�czy dzia�ania z w�asnej inicjatywy, trzeba go przerwa� przez Ctrl-C.
Sprawd� czy oba programy prawid�owo ze sob� wsp�pracuj�. Uruchom je na tym samym komputerze, tak aby jako adres IPv4 mo�na by�o poda� 127.0.0.1 (to zawsze oznacza lokaln� maszyn�).