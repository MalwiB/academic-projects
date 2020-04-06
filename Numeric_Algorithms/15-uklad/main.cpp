#include <iostream>
#include <cmath>
#include <set>
#include <unistd.h>
#define EPSILON 1e-8

using namespace std;

void g(double x, double y, double tab_g[2]) {
   double wartosc1 = (x*y) - exp(-x + y);
   double wartosc2 = sin(x*x+y) - (0.9*x);
   tab_g[0] = wartosc1;
   tab_g[1] = wartosc2;
}

void jakobian(double x, double y, double macierz[2][2]) {
   // df1/dx
   macierz[0][0] = exp(-x)*(exp(x)*y+exp(y));
   // df1/dy
   macierz[0][1] = x - exp(y-x);
   // df2/dx
   macierz[1][0] = 2*(x*cos(x*x+y)-0.45);
   // df2/dy
   macierz[1][1] = cos(x*x+y);
}

void jakobian_odwrotnosc(double x, double y, double macierz[2][2]) {
   jakobian(x, y, macierz);
   double a = macierz[0][0];
   double b = macierz[0][1];
   double c = macierz[1][0];
   double d = macierz[1][1];
   double wspolczynnik = 1/(a*d-b*c);
   macierz[0][0] = wspolczynnik*d;
   macierz[0][1] = wspolczynnik*(-b);
   macierz[1][0] = wspolczynnik*(-c);
   macierz[1][1] = wspolczynnik*a;
}

double norma(double wektor[2]) {
   double suma_kwadratow=0, norma=0;
   int i;
   for(i=0;i<2;i++) {
      suma_kwadratow += wektor[i]*wektor[i];
   }
   norma = sqrt(suma_kwadratow);
   return norma;
}

void odejmowanie_wektorow(double wektor[2], double wektor_odejmowany[2]) {
   int i;
   for(i=0;i<2;i++) {
      wektor[i] = wektor[i] - wektor_odejmowany[i];
   }
}

void mnozenie_macierz_wektor(double tab[2][2], double wektor[2], double wektor_do_zapisu[2]) {
   int i, j;
   for(i=0;i<2;i++) {
      wektor_do_zapisu[i] = 0;
   }
   for(i=0;i<2;i++) {
      for(j=0;j<2;j++) {
         wektor_do_zapisu[i] += tab[i][j]*wektor[j];
      }
   }
}

bool sprawdzanie_powtorzenia(set<pair<double, double>>* rozwiazania, pair<double, double> para_do_wstaw) {
   for(pair<double, double> p : *rozwiazania) {
      if(abs(p.first-para_do_wstaw.first)<1e-4 && abs(p.second-para_do_wstaw.second)<1e-4) {   //prawdopodobnie sa takie same
         return true;   //jest powtorzenie
      }
   }
   return false;
}

void metoda_Newtona_uklady(set<pair<double, double>>* rozwiazania) {
   double x[2] = {((double) rand() / RAND_MAX) * 4 - 1. , ((double) rand() / RAND_MAX) * 4 - 1.};
   // pomocnicze:
   double tab_g[2] = {0, 0};
   double tab_jac[2][2] = {0};
   double pomnozone[2] = {0, 0};
   int iteracje = 0;
   do {
      g(x[0], x[1], tab_g);
      jakobian_odwrotnosc(x[0], x[1], tab_jac);
      mnozenie_macierz_wektor(tab_jac, tab_g, pomnozone);
      odejmowanie_wektorow(x, pomnozone);
      iteracje++;
      if(iteracje>100)
         return;
   } while(norma(tab_g) >= EPSILON);
   pair<double, double> para(x[0], x[1]);
   if(sprawdzanie_powtorzenia(rozwiazania, para) == false)
      rozwiazania->insert(para);
}

int main() {
   set<pair<double, double>>* rozwiazania = new set<pair<double, double>>();
   int i;
   for(i=0;i<50;i++) {   //program wykonuje okreslona liczbe poszukiwan rozwiazan
      metoda_Newtona_uklady(rozwiazania);
   }
   
   cout << "Znaleziono "<<rozwiazania->size() << " rozwiazania.\n";
   for(pair<double, double> p : *rozwiazania)
      cout << "x: " << p.first << ", y: " << p.second << endl;
   delete rozwiazania;
   return 0;
}