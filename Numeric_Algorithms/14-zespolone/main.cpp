#include <iostream>
#include <utility>
#include <cmath>
#include <complex>
#include <unistd.h>
#define EPSILON 1e-8

using namespace std;

// liczba zespolona: z = a+b*i
// rownanie do rozwiazania: z^3 - 1 = 0
// musimy wyznaczyc takie a i b, zeby z^3 -1 =0
complex<double> f(complex<double> liczba_zespolona) {
   double rzecz = liczba_zespolona.real();
   double uroj = liczba_zespolona.imag();
   complex<double> temp ((rzecz*rzecz*rzecz - 3*rzecz*uroj*uroj - 1), (3*rzecz*rzecz*uroj - uroj*uroj*uroj));
   return temp;
}

complex<double> pierwsza_pochodna_f(complex<double> liczba_zespolona) {
   double rzecz = liczba_zespolona.real();
   double uroj = liczba_zespolona.imag();
   complex<double> temp ((3*rzecz*rzecz - 3*uroj*uroj), (6*rzecz*uroj));
   return temp;
}

void metoda_Newtona(complex<double>* tablica_pocz_przedzialow, complex<double>* tablica_konc_przedzialow) {
   int i;
   for(i=0;i<3;i++) {   //szukamy miejsca zerowego dla kazdego przedzialu
      complex<double> zero(0,0);
      if(f(tablica_pocz_przedzialow[i]) == zero) {
         cout << "Metoda Newtona dla przedzialu [" << tablica_pocz_przedzialow[i] << ";" << tablica_konc_przedzialow[i] << "] daje miejsce zerowe (w przyblizeniu): " << tablica_pocz_przedzialow[i]<<endl;
      }
      else if(f(tablica_pocz_przedzialow[i]) == zero) {
         cout << "Metoda Newtona dla przedzialu [" << tablica_pocz_przedzialow[i] << ";" << tablica_konc_przedzialow[i] << "] daje miejsce zerowe (w przyblizeniu): " << tablica_konc_przedzialow[i]<<endl;
      }
      else {
         complex<double> poczatek = tablica_pocz_przedzialow[i];
         complex<double> koniec = tablica_konc_przedzialow[i];
         complex<double> x = (f(poczatek)*koniec - f(koniec)*poczatek)/(f(poczatek) - f(koniec));
         int ilosc_krokow = 0;
         while(abs(f(x)) > EPSILON) {
            x = x - (f(x)/pierwsza_pochodna_f(x));
            ilosc_krokow++;
         }
         cout << "Metoda Newtona dla przedzialu [" << tablica_pocz_przedzialow[i] << ";" << tablica_konc_przedzialow[i] << "] daje miejsce zerowe (w przyblizeniu): " << x <<". ";
         cout << "Zrobila to w "<< ilosc_krokow << " krokach.\n";
      }
   }
}

int main() {
   complex<double> tablica_pocz_przedzialow[3] = {0};
   complex<double> tablica_konc_przedzialow[3] = {0};
   // Sa 3 rozw, a wiec bedziemy ich szukac w 3 pierwszych cwiartkach
   // Ustalamy przedzialy cwiartek:
   // 1 CWIARTKA:
   tablica_pocz_przedzialow[0] = complex<double>(1, 0);
   tablica_konc_przedzialow[0] = complex<double>(0, 1);
   // 2 CW
   tablica_pocz_przedzialow[1] = complex<double>(0, 1);
   tablica_konc_przedzialow[1] = complex<double>(-1, 0);
   // 3 CW
   tablica_pocz_przedzialow[2] = complex<double>(-1, 0);
   tablica_konc_przedzialow[2] = complex<double>(0, -1);
   
   int i;
   cout << "Przedzialy w ktorych bedziemy szukac miejsc zerowych:\n";
   for (i=0;i<3;i++) {
      cout << tablica_pocz_przedzialow[i] << " " << tablica_konc_przedzialow[i] << endl;
   }
   
   cout << "Wyniki METODY NEWTON'A dla rownania liczb zespolonych:\n";
   metoda_Newtona(tablica_pocz_przedzialow, tablica_konc_przedzialow);
   
   return 0;
}