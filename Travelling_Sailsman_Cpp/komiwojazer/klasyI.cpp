#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "klasyI.hpp"
#include "hamilton.hpp"
#include "inne_funkcje.hpp"


ostream& operator << (ostream& os, Wierzcholek w) {
	return os << "Wierzcholek numer: " << w.numer << "   (" << w.x << "," << w.y << ")" << endl;
}

ostream& operator << (ostream& os, Krawedz k) {
	return os << "Wierzcholki krawedzi: " << k.w1 << " i " << k.w2 << ". Odleglosc: " << endl;
}



