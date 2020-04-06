Implementacja serwera wspó³bie¿nego, wykorzystuj¹cego funkcjê epoll, która obs³uguje przychodz¹ce po³¹czenia.
Po³¹czenia s¹ akceptowane w pêtli, po czym nastêpuje odbieranie danych z gniazd.
Podczas odbierania danych mog¹ siê pojawiæ nowe po³¹czenia i równie¿ zostan¹ obs³u¿one.
