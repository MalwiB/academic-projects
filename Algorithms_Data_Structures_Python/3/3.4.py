# program pobiera napis od uzytkownika
# sprawdza czy jest to liczba, jesli nie to komunikat
# wypisuje te liczbe i jej trzecia potege

liczba = raw_input("Podaj liczbe: ")
while liczba:
	if not liczba.isdigit():
		if liczba == "stop":
			break;
		else:
			print "To nie jest ani liczba ani stop\n"
	else:
		print "Trzecia potega liczby " + liczba + " to " + str(pow(int(liczba), 3)) + "\n"
	liczba = raw_input("Podaj liczbe: ")