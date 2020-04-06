http://users.uj.edu.pl/~palacz/edu/201617-PS/index.html


1. Wizytówki serwerów

Termin oddania finalnej wersji rozwi¹zania: 2017-03-20. Obowi¹zuje jêzyk C.
Wiele protoko³ów sieciowych korzysta z czegoœ w rodzaju wizytówki: po nawi¹zaniu po³¹czenia miêdzy klientem a serwerem serwer, nie czekaj¹c na ¿adne dane od klienta, wysy³a liniê tekstu. Przez „liniê tekstu” nale¿y rozumieæ ci¹g drukowalnych znaków ASCII zakoñczony dwuznakiem \r\n (choæ czasem linia zakoñczona jest tylko znakiem \n). Informacje zawarte w tej linii przewa¿nie pozwalaj¹ klientowi zorientowaæ siê któr¹ wersjê protoko³u obs³uguje serwer, jakie oprogramowanie dzia³a na serwerze, itp.
Napisz program-klienta, który bêdzie ³¹czy³ siê (u¿yj socket i connect) z us³ug¹ wskazan¹ argumentami podanymi w linii komend (adres IPv4 w argv[1], numer portu TCP w argv[2]), drukowa³ na ekranie wizytówkê zwrócon¹ przez serwer, i zamyka³ po³¹czenie. Pamiêtaj o zasadzie ograniczonego zaufania i weryfikuj czy odebrane bajty to na pewno drukowalne znaki zanim je przeœlesz na stdout.
Przetestuj program ³¹cz¹c siê z nastêpuj¹cymi us³ugami:

149.156.43.64 22 (us³uga SSH)
149.156.89.147 25 (us³uga SMTP)
193.219.28.2 21 (us³uga FTP)
193.219.28.2 873 (us³uga rsync)
149.156.225.215 80 (us³uga HTTP)

W tym ostatnim przypadku klient powinien siê zawiesiæ, bo serwery HTTP nie wysy³aj¹ wizytówek. Trzeba bêdzie rêcznie przerwaæ jego nieskoñczone oczekiwanie naciskaj¹c kombinacjê klawiszy Ctrl-C.

Uwaga: nie próbuj testowaæ klienta uruchamiaj¹c go na serwerze spk-ssh.if.uj.edu.pl, bo nie zadzia³a. Ten serwer dostêpowy dla bezpieczeñstwa jest obwarowany firewallami blokuj¹cymi próby otwierania po³¹czeñ wychodz¹cych do wiêkszoœci us³ug (z powy¿szej listy przepuszcza tylko HTTP).
Napisz drugi program, który bêdzie atrap¹ serwera. Powinien stworzyæ sobie gniazdko TCP nas³uchuj¹ce na porcie o numerze podanym jako argv[1] (u¿yj socket, bind i listen), nastêpnie w pêtli czekaæ na przychodz¹ce po³¹czenia (accept), wysy³aæ ci¹g "Hello, world!\r\n" jako swoj¹ wizytówkê, zamykaæ odebrane po³¹czenie, i wracaæ na pocz¹tek pêtli. Program nie koñczy dzia³ania z w³asnej inicjatywy, trzeba go przerwaæ przez Ctrl-C.
SprawdŸ czy oba programy prawid³owo ze sob¹ wspó³pracuj¹. Uruchom je na tym samym komputerze, tak aby jako adres IPv4 mo¿na by³o podaæ 127.0.0.1 (to zawsze oznacza lokaln¹ maszynê).