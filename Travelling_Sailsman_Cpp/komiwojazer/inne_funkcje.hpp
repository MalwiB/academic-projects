#ifndef inne_funkcje_hpp
#define inne_funkcje_hpp

double obliczOdleglosc(Wierzcholek a, Wierzcholek b);

void mieszajTablice(Wierzcholek* tab, int size);

bool czyBylaWylosowana(int iLiczba, vector<int> tab, int ile);

vector<int> losowanieBezPowtorzen(int lUczestnikowTurnieju, int ileLiczb);

pair<CyklHamiltona, CyklHamiltona> turniej(vector<CyklHamiltona> wylosowaneDoTurnieju);

pair<int, int> losowanieIndeksow(int n);

bool dzieckoJuzMa(Wierzcholek l, CyklHamiltona dziecko, int size);

CyklHamiltona krzyzowanie(pair<CyklHamiltona, CyklHamiltona> rodzice);

void mutacja(vector<CyklHamiltona>* populacjaCykli, double wspolczynnikMutacji);


#endif // !inne_funkcje_hpp