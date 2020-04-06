#ifndef komiwojazer_hpp
#define komiwojazer_hpp

using namespace std;

const int liczbaIteracji = 15;
const int wielkoscPopulacji = 100;


class Wierzcholek {
public:
	int numer = 0;
	double x = 0;
	double y = 0;
	Wierzcholek() {};
	Wierzcholek(int n) : numer(n) {}
	Wierzcholek(int n, double ax, double ay) : numer(n), x(ax), y(ay) {}

	operator int() const {
		return numer;
	}

	friend ostream& operator << (ostream& os, Wierzcholek w);
};


class Krawedz {
public:
	Wierzcholek w1 = NULL;
	Wierzcholek w2 = NULL;

	Krawedz() {}
	Krawedz(Wierzcholek& w1, Wierzcholek& w2) {
		this->w1 = w1;
		this->w2 = w2;
	}

	friend ostream& operator << (ostream& os, Krawedz k);
};









#endif // !komiwojazer_hpp
