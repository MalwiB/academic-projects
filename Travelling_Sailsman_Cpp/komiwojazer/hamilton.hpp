#ifndef hamilton_hpp
#define hamilton_hpp

class CyklHamiltona;

class Graf {	//pelny
				//reprezentacja grafu: za pomoca macierzy sasiedztwa
				//dla ulatwienia- WIERZCHOLKI SA NUMEROWANE PO KOLEI! tak trzeba je dodawac
				//graf pelny-
				//graf posiadajacy polaczenie kazda krawedz z kazda krawedzia
				//wystarczy dodawac same wierzcholki, sa one laczone z reszta wierzcholkow automatycznie
				//w macierzy sasiedztwa znajduja sie odleglosci miedzy danymi wierzcholkami
public:
	int lWierzcholkow = 0;
	int licznikWierzcholkow = 0;
	Wierzcholek* macierzWierzcholkow;
	double** macierzSasiedztwa;

	Graf() {}
	Graf(int n) : lWierzcholkow(n + 1) {
		//tworzymy tablice sasiedztwa
		macierzWierzcholkow = new Wierzcholek[lWierzcholkow];
		macierzSasiedztwa = new double*[lWierzcholkow];
		int i;
		for (i = 0; i < lWierzcholkow; i++)
			macierzSasiedztwa[i] = new double[lWierzcholkow];

		//inicjalizacja tablicy
		int j;
		for (i = 0; i < lWierzcholkow; i++)
			for (j = 0; j < lWierzcholkow; j++)
				macierzSasiedztwa[i][j] = 1;
	}

	~Graf() {
		int i;
		for (i = 0; i < lWierzcholkow; i++)
			delete[] macierzSasiedztwa;
		delete[] macierzWierzcholkow;
	}


	double wybierzZTablicy(int i1, int i2) {
		return macierzSasiedztwa[i1][i2];
	}


	void dodajWierzcholek(Wierzcholek w) {
		macierzWierzcholkow[licznikWierzcholkow++] = w;
	}

	void dodajKrawedz(Krawedz k) {
		macierzSasiedztwa[k.w1][k.w2] = 1;
		macierzSasiedztwa[k.w2][k.w1] = 1;
	}

	void wypiszMacierz() {
		int i, j;
		cout.precision(3);
		cout << "       ";
		for (i = 0;i<lWierzcholkow;i++) {
			cout.width(5);
			cout << i << "      ";
			cout.width(5);
		}
		cout << endl;
		for (i = 0;i<lWierzcholkow;i++) {
			cout.width(5);
			cout << i << "  ";
			for (j = 0;j<lWierzcholkow;j++) {
				cout.width(5);
				cout << macierzSasiedztwa[i][j] << "      ";
			}
			cout << endl;
		}
	}

	void obliczOdleglosci();
	void jakDobryCykl(CyklHamiltona* cykl);
	void znajdzCyklHamiltona(Wierzcholek* wszystkieMiasta, int size);
};

class CyklHamiltona {   //klasa- gatunek, obiekt- osobnik
public:
	vector<Wierzcholek> wektorMiast;
	double waga = 0;
	int numerWPopulacji = 0;

	CyklHamiltona() {}
	CyklHamiltona(int n) : wektorMiast(n) {}

	void dodajDoCyklu(Wierzcholek w) {
		wektorMiast.push_back(w);

	}

	void dodajDoCyklu(Wierzcholek* tablica, int rozmiar) {
		int i;
		for (i = 0;i<rozmiar;i++) {
			wektorMiast.push_back(tablica[i]);
		}
	}

	int size() {
		return wektorMiast.size();
	}

	int operator[](int i) { //napisac, zeby estetycznie robic
		return wektorMiast[i];
	}


	int operator==(CyklHamiltona c2) {
		int i;
		if (wektorMiast.size() != c2.wektorMiast.size())
			return false;
		for (i = 0;i<wektorMiast.size();i++) {
			if (wektorMiast[i] != c2.wektorMiast[i])
				return false;
		}
		return true;
	}

	int operator>(CyklHamiltona c) {
		if (this->waga > c.waga)
			return true;
		else
			return false;
	}


	friend ostream& operator << (ostream& os, CyklHamiltona c) {
		os << "Przebieg cyklu: \n";
		for (vector<Wierzcholek>::iterator it = c.wektorMiast.begin(); it != c.wektorMiast.end(); ++it)
			os << (*it).numer << " ";
		os << endl;
		os << "Jak dobry: " << c.waga << endl;
		return os;
	}

};







#endif // !hamilton_hpp

