Implementacja serwera wsp�bie�nego, wykorzystuj�cego funkcj� epoll, kt�ra obs�uguje przychodz�ce po��czenia.
Po��czenia s� akceptowane w p�tli, po czym nast�puje odbieranie danych z gniazd.
Podczas odbierania danych mog� si� pojawi� nowe po��czenia i r�wnie� zostan� obs�u�one.
