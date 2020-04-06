#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "klasyI.hpp"
#include "hamilton.hpp"
#include "inne_funkcje.hpp"

void Graf::obliczOdleglosci() {
	int i, j;
	for (i = 0; i < lWierzcholkow; i++)
		for (j = 0; j < lWierzcholkow; j++) {
			if (i != j) {
				macierzSasiedztwa[i][j] = obliczOdleglosc(macierzWierzcholkow[i], macierzWierzcholkow[j]);
				macierzSasiedztwa[j][i] = macierzSasiedztwa[i][j];
			}
			else
				macierzSasiedztwa[i][j] = 0;
		}

}


void Graf::jakDobryCykl(CyklHamiltona* cykl) {
	double jakDobry = 0;
	int i;
	cout << "sumujemy (jakDobryCykl): ";
	for (i = 0;i<cykl->size() - 1;i++) { //wagi krawedzi, wiec o 1 mniej
		jakDobry += macierzSasiedztwa[cykl->wektorMiast[i]][cykl->wektorMiast[i + 1]];
		cout << macierzSasiedztwa[cykl->wektorMiast[i]][cykl->wektorMiast[i + 1]] << " ";
	}
	cout << endl << "Suma calkowita: " << jakDobry << endl;
	cykl->waga = jakDobry;

}


void Graf::znajdzCyklHamiltona(Wierzcholek* wszystkieMiasta, int size) {
	//wektor wkaznikow do osobnikow
	vector<CyklHamiltona> populacjaCykli;
	vector<CyklHamiltona> populacjaCykliKopia;

	//tworzymy cala populacje osobnikow losowo(aby byla duza roznorodnosc),
	//mieszamy miejscowosci w tablicy i podajemy do cyklu
	cout << "\nTWORZENIE LOSOWEJ POPULACJI: " << endl;
	int i;
	for (i = 0;i<wielkoscPopulacji;i++) {
		mieszajTablice(wszystkieMiasta, size);
		CyklHamiltona cykl;
		cykl.numerWPopulacji = i;
		cykl.dodajDoCyklu(wszystkieMiasta, size);
		populacjaCykli.push_back(cykl);
		//cout <<cykl<<endl;
	}

	//badamy jak dobre sa cykle:
	for (i = 0;i<populacjaCykli.size();i++)
		jakDobryCykl(&populacjaCykli[i]);

	//po to, zeby wypisac na koncu, dla porownania
	populacjaCykliKopia = populacjaCykli;

	//warunek, zeby program nie trwal w nieskonczonosc- liczba iteracji
	// przy zwiekszaniu ilosci iteracji, dokladnosc bedzie wieksza, ale czas sie zwiekszy
	int iteracja;
	for (iteracja = 0;iteracja<liczbaIteracji;iteracja++) {
		vector<CyklHamiltona> wylosowaneDoTurnieju;
		pair<CyklHamiltona, CyklHamiltona> rodzice;
		pair<CyklHamiltona, CyklHamiltona> dzieci;

		//krok selekcji, czyli wybor do nastepnej populacji osobników najlepiej przystosowanych
		//(to znaczy takich które reprezentuja trasy o najmniejszym koszcie)
		//tutaj wybieramy metoda "turnieju"
		int lUczestnikowTurnieju = 5;
		int ileLiczb = populacjaCykli.size();
		cout << "PopulacjaCykli: " << populacjaCykli.size() << endl;
		cout << endl << "ilu uczestnikow w turnieju: " << lUczestnikowTurnieju << ", ileLiczb: " << ileLiczb << endl;
		vector<int> tabBezPowtorzen = losowanieBezPowtorzen(lUczestnikowTurnieju, ileLiczb);
		cout << "\nTURNIEJ:\n";
		for (i = 0;i<lUczestnikowTurnieju;i++) {   //losowanie grup do turnieju
			cout << "Uczestnik numer: " << tabBezPowtorzen[i] << endl;
			wylosowaneDoTurnieju.push_back(populacjaCykli[tabBezPowtorzen[i]]);
			cout << wylosowaneDoTurnieju[i] << endl;
		}
		rodzice = turniej(wylosowaneDoTurnieju);
		wylosowaneDoTurnieju.clear();
		cout << "Pierwszy rodzic: " << rodzice.first << endl;
		cout << "Drugi rodzic: " << rodzice.second << endl;

		//krzyzowanie polega na wymianie pomedzy dwoma osobnikami podtras
		//bierzemy fragment podtrasy z pierwszego rodzica, a reszte uzupelniamy drugim

		cout << "Dziecko pierwsze: \n";
		dzieci.first = krzyzowanie(rodzice);
		dzieci.first.numerWPopulacji = rodzice.first.numerWPopulacji;
		jakDobryCykl(&dzieci.first);
		populacjaCykli[rodzice.first.numerWPopulacji] = dzieci.first;
		cout << dzieci.first << endl;

		cout << "Dziecko drugie: \n";
		dzieci.second = krzyzowanie(rodzice);
		dzieci.second.numerWPopulacji = rodzice.second.numerWPopulacji;
		jakDobryCykl(&dzieci.second);
		populacjaCykli[rodzice.second.numerWPopulacji] = dzieci.second;
		cout << dzieci.second << endl;

		// mutacja oznaczac kilka miast zamienionych miejscami w osobniku
		//wspolczynnik mutacji (ile osobnikow ulegnie przestawieniu trasy)
		double wspolczynnikMutacji = 0.1;
		mutacja(&populacjaCykli, wspolczynnikMutacji);

	}

	//ostateczne sortowanie, najkrotsza mozemy uznac za przyblizony wynik poszukiwan
	pair<CyklHamiltona, CyklHamiltona> c = turniej(populacjaCykli);
	cout << "Wynik: \n";
	cout << c.first << endl;

	cout << "DLA POROWNANIA CZESC LOSOWych DANCYCH WEJSCIOWYCH: \n";
	for (i = 0;i<6;i++)
		cout << populacjaCykliKopia[i] << endl;

}