#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "klasyI.hpp"
#include "hamilton.hpp"
#include "inne_funkcje.hpp"



using namespace std;


int main() {

int iloscWierzcholkow=8;

Graf g3(iloscWierzcholkow);

Wierzcholek w0(0,2,1);
Wierzcholek w1(1,1,2);
Wierzcholek w2(2,2,4);
Wierzcholek w3(3,3,3);
Wierzcholek w4(4,5,5);
Wierzcholek w5(5,7,3);
Wierzcholek w6(6,5,1);
//manipulowanie iloscia wierzcholkow
//widac radykalne zmiany wynikow miedzy pierwsza generacja a ostatnia
Wierzcholek w7(7,19, 6);
Wierzcholek w8(8,2,11);


Wierzcholek* tablicaMiast = new Wierzcholek[iloscWierzcholkow+1];
tablicaMiast[0] = w0;
tablicaMiast[1] = w1;
tablicaMiast[2] = w2;
tablicaMiast[3] = w3;
tablicaMiast[4] = w4;
tablicaMiast[5] = w5;
tablicaMiast[6] = w6;
tablicaMiast[7] = w7;
tablicaMiast[8] = w8;


int i;
for(i=0;i<iloscWierzcholkow+1;i++)
    g3.dodajWierzcholek(tablicaMiast[i]);
g3.obliczOdleglosci();

cout <<"MACIERZ SASIEDZTWA DLA WIERZCHOLKOW: \n"<<endl;
g3.wypiszMacierz();

srand(time(0));

g3.znajdzCyklHamiltona(tablicaMiast,iloscWierzcholkow+1);


getchar();

//zwalnianie pamieci:
delete[] tablicaMiast;

}
