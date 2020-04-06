#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "klasyI.hpp"
#include "hamilton.hpp"
#include "inne_funkcje.hpp"

double obliczOdleglosc(Wierzcholek a, Wierzcholek b) {
	double roznicaX = abs(a.x - b.x);
	double roznicaY = abs(a.y - b.y);
	return sqrt(roznicaX*roznicaX + roznicaY*roznicaY);
}

void mieszajTablice(Wierzcholek* tab, int size) {   //prosta funkcja mieszajaca tablice
	Wierzcholek temp;
	int i;
	for (i = 0;i<size + 5;i++) {
		int l1 = rand() % size;
		int l2 = rand() % size;
		temp = tab[l1];
		tab[l1] = tab[l2];
		tab[l2] = temp;
	}
}

bool czyBylaWylosowana(int iLiczba, vector<int> tab, int ile) {
	if (ile <= 0)
		return false;
	int i = 0;
	do {
		if (tab[i] == iLiczba)
			return true;
		i++;
	} while (i < ile);

	return false;
}



vector<int> losowanieBezPowtorzen(int lUczestnikowTurnieju, int ileLiczb) {
	vector<int> tab;
	do {
		int liczba = rand() % ileLiczb;
		if (czyBylaWylosowana(liczba, tab, tab.size()) == false) {
			cout << liczba << " ";
			tab.push_back(liczba);
		}
	} while (tab.size() < lUczestnikowTurnieju);
	cout << endl;
	return tab;
}




//wybieranie najlepszego
//malo elementow do porownania, wiec nie musi byc zbyt wyrafinowane
pair<CyklHamiltona, CyklHamiltona> turniej(vector<CyklHamiltona> wylosowaneDoTurnieju) {
	pair<CyklHamiltona, CyklHamiltona> temp;
	int i, j;
	for (int i = 0;i<wylosowaneDoTurnieju.size();i++)
		for (int j = 1;j<wylosowaneDoTurnieju.size() - i;j++)
			if (wylosowaneDoTurnieju[j - 1]>wylosowaneDoTurnieju[j])
				swap(wylosowaneDoTurnieju[j - 1], wylosowaneDoTurnieju[j]);
	temp.first = wylosowaneDoTurnieju[0];
	temp.second = wylosowaneDoTurnieju[1];
	return temp;
}

pair<int, int> losowanieIndeksow(int n) {
	pair<int, int> indeksy;
	indeksy.first = rand() % (n / 2);
	indeksy.second = rand() % (n / 2) + 3;
	if (indeksy.first > indeksy.second) {
		int temp;
		temp = indeksy.first;
		indeksy.first = indeksy.second;
		indeksy.second = temp;
	}
	return indeksy;
}


bool dzieckoJuzMa(Wierzcholek l, CyklHamiltona dziecko, int size) {
	int i;
	for (i = 0;i<size;i++)
		if (dziecko.wektorMiast[i] == l)
			return true;

	return false;
}


CyklHamiltona krzyzowanie(pair<CyklHamiltona, CyklHamiltona> rodzice) {
	CyklHamiltona dziecko(rodzice.second.size());
	pair<int, int> indeksy;
	indeksy = losowanieIndeksow(rodzice.first.size());
	cout << "Indeksy: od " << indeksy.first << " do " << indeksy.second << endl;

	int i, j = 0;
	for (i = indeksy.first;i <= indeksy.second;i++) {  //przekazywane z pierwszego z rodzicow w wylosowanym zakresie
		dziecko.wektorMiast[i] = rodzice.first[i];
	}

	for (i = 0;i<indeksy.first;i++)   //ustawianie na reszcie pozycji NULL'a
		dziecko.wektorMiast[i] = -1;
	for (i = indeksy.second + 1;i<rodzice.first.size();i++)
		dziecko.wektorMiast[i] = -1;

	for (i = 0;i<rodzice.second.size();i++) {   //uzupelnianie z drugiego rodzicow reszty
		Wierzcholek l = rodzice.second[i];
		if (!dzieckoJuzMa(l, dziecko, rodzice.first.size())) {
			while (dziecko.wektorMiast[j] != -1)
				j++;
			dziecko.wektorMiast[j] = l;
		}
	}

	return dziecko;
}


void mutacja(vector<CyklHamiltona>* populacjaCykli, double wspolczynnikMutacji) {
	int ileZmutowanych = wspolczynnikMutacji*populacjaCykli->size();
	cout << "Zmutowanych bedzie: " << ileZmutowanych << endl;

	int i;
	for (i = 0;i<ileZmutowanych;i++) {
		//losujemy osobnika do zmutowania
		int numerOsobnika = rand() % populacjaCykli->size();
		CyklHamiltona* mutujacy;
		mutujacy = &(*populacjaCykli)[numerOsobnika];
		cout << "Osobnik, ktory ma zmutowac: \n" << *mutujacy << endl;
		Wierzcholek temp;
		pair<int, int> zamianaIndeksow = losowanieIndeksow(mutujacy->size());

		temp = mutujacy->wektorMiast[zamianaIndeksow.first];
		mutujacy->wektorMiast[zamianaIndeksow.first] = mutujacy->wektorMiast[zamianaIndeksow.second];
		mutujacy->wektorMiast[zamianaIndeksow.second] = temp;

		cout << "Osobnik juz zmutowal: \n" << *mutujacy << endl;
		(*populacjaCykli)[numerOsobnika] = *mutujacy;
	}

}