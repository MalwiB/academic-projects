#include <stdio.h>
#include <math.h>
#define EPSILON 1e-8

// wyliczone wolframem rownanie charakterystyczne, czyli nasza funkcja:
// -lambda^3 + 4*lambda^2 + 39*lambda -1 = 0
double f(double lambda) {
   double wartosc = -(lambda * lambda * lambda) + (4 * lambda * lambda) + (39 * lambda) - 1;
   return wartosc;
}

// -3*lambda^2 + 8*lambda + 39
double pierwsza_pochodna_f(double lambda) {
   double wynik = ((-3) * lambda * lambda) + 8 * lambda + 39;
   return wynik;
}

// -6 * lambda + 8
double druga_pochodna_f(double lambda) {
   double wynik = ((-6) * lambda) + 9;
   return wynik;
}

int jaki_znak(double a) {
   if (f(a) > 0)
      return 1;
   else
      return -1;
}
void szukanie_przedzialow(double* tablica_pocz_przedzialow, double* tablica_konc_przedzialow) {
   // jesli znak == -1 to w przedziale w ktorym jestesmy znak jest ujemny, dla == 1 jest dodatni
   int pocz_zakresu = -100;
   int koniec_zakresu = 100;
   int znak = jaki_znak(-100);
   int licznik = 0;
   while(pocz_zakresu < koniec_zakresu) { //wedrujemy caly czas po zakresie od -100 az dojdziemy do 100
      if(znak != jaki_znak(pocz_zakresu)) {
         znak = jaki_znak(pocz_zakresu);
         tablica_pocz_przedzialow[licznik] = pocz_zakresu-1;
         tablica_konc_przedzialow[licznik] = pocz_zakresu;
         licznik++;
      }
      pocz_zakresu++; //przesuwamy sie po przedziale o jakas dlugosc
   }
}

// implementacja metod
void metoda_bisekcji(double* tablica_pocz_przedzialow, double* tablica_konc_przedzialow) {
   int i;
   for(i=0;i<3;i++) {   //szukamy miejsca zerowego dla kazdego przedzialu
      if(f(tablica_pocz_przedzialow[i]) == 0) {
         printf("Metoda bisekcji dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], tablica_pocz_przedzialow[i]);
      }
      else if(f(tablica_pocz_przedzialow[i]) == 0) {
         printf("Metoda bisekcji dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], tablica_konc_przedzialow[i]);
      }
      else {
         double poczatek = tablica_pocz_przedzialow[i];
         double koniec = tablica_konc_przedzialow[i];
         double x = (poczatek + koniec)/2;
         int ilosc_krokow = 0;
         while(fabs(f(x)) > EPSILON) {
            if(f(poczatek)*f(x)<0) {  //funkcja zmienia znak w przedziale [poczatek;x]
               koniec = x;
            }
            else {   //funkcja zmienia znak w przedziale [x;koniec]
               poczatek = x;
            }
            x = (poczatek + koniec)/2;
            ilosc_krokow++;
         }
         printf("Metoda bisekcji dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], x);
         printf("Zrobila to w %d krokach.\n", ilosc_krokow);
      }
   }
}

void metoda_regula_falsi(double* tablica_pocz_przedzialow, double* tablica_konc_przedzialow) {
   int i;
   for(i=0;i<3;i++) {   //szukamy miejsca zerowego dla kazdego przedzialu
      if(f(tablica_pocz_przedzialow[i]) == 0) {
         printf("Metoda regula-falsi dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], tablica_pocz_przedzialow[i]);
      }
      else if(f(tablica_pocz_przedzialow[i]) == 0) {
         printf("Metoda regula-falsi dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], tablica_konc_przedzialow[i]);
      }
      else {
         double poczatek = tablica_pocz_przedzialow[i];
         double koniec = tablica_konc_przedzialow[i];
         double x = (poczatek + koniec)/2;
         int ilosc_krokow = 0;
         while(fabs(f(x)) > EPSILON) {
            if(f(poczatek)*f(x)<0) {  //funkcja zmienia znak w przedziale [poczatek;x]
               koniec = x;
            }
            else {   //funkcja zmienia znak w przedziale [x;koniec]
               poczatek = x;
            }
            x = (f(poczatek)*koniec - f(koniec)*poczatek)/(f(poczatek) - f(koniec));
            ilosc_krokow++;
         }
         printf("Metoda regula-falsi dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], x);
         printf("Zrobila to w %d krokach.\n", ilosc_krokow);
      }
   }
}

void metoda_siecznych(double* tablica_pocz_przedzialow, double* tablica_konc_przedzialow) {
   int i;
   for(i=0;i<3;i++) {   //szukamy miejsca zerowego dla kazdego przedzialu
      if(f(tablica_pocz_przedzialow[i]) == 0) {
         printf("Metoda siecznych dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], tablica_pocz_przedzialow[i]);
      }
      else if(f(tablica_pocz_przedzialow[i]) == 0) {
         printf("Metoda siecznych dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], tablica_konc_przedzialow[i]);
      }
      else {
         double poczatek = tablica_pocz_przedzialow[i];
         double koniec = tablica_konc_przedzialow[i];
         double x = (f(poczatek)*koniec - f(koniec)*poczatek)/(f(poczatek) - f(koniec));
         int ilosc_krokow = 0;
         while(fabs(f(x)) > EPSILON) {
            poczatek = koniec;
            koniec = x;
            x = (f(poczatek)*koniec - f(koniec)*poczatek)/(f(poczatek) - f(koniec));
            ilosc_krokow++;
         }
         printf("Metoda siecznych dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], x);
         printf("Zrobila to w %d krokach.\n", ilosc_krokow);
      }
   }
}

void metoda_Newtona(double* tablica_pocz_przedzialow, double* tablica_konc_przedzialow) {
   int i;
   for(i=0;i<3;i++) {   //szukamy miejsca zerowego dla kazdego przedzialu
      if(f(tablica_pocz_przedzialow[i]) == 0) {
         printf("Metoda Newtona dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], tablica_pocz_przedzialow[i]);
      }
      else if(f(tablica_pocz_przedzialow[i]) == 0) {
         printf("Metoda Newtona dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], tablica_konc_przedzialow[i]);
      }
      else {
         double poczatek = tablica_pocz_przedzialow[i];
         double koniec = tablica_konc_przedzialow[i];
         double x = (f(poczatek)*koniec - f(koniec)*poczatek)/(f(poczatek) - f(koniec));
         int ilosc_krokow = 0;
         while(fabs(f(x)) > EPSILON) {
            x = x - (f(x)/pierwsza_pochodna_f(x));
            ilosc_krokow++;
         }
         printf("Metoda Newtona dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], x);
         printf("Zrobila to w %d krokach.\n", ilosc_krokow);
      }
   }
}

void metoda_Halleya(double* tablica_pocz_przedzialow, double* tablica_konc_przedzialow) {
   int i;
   for(i=0;i<3;i++) {   //szukamy miejsca zerowego dla kazdego przedzialu
      if(f(tablica_pocz_przedzialow[i]) == 0) {
         printf("Metoda Newtona dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], tablica_pocz_przedzialow[i]);
      }
      else if(f(tablica_pocz_przedzialow[i]) == 0) {
         printf("Metoda Newtona dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], tablica_konc_przedzialow[i]);
      }
      else {
         double poczatek = tablica_pocz_przedzialow[i];
         double koniec = tablica_konc_przedzialow[i];
         double x = (f(poczatek)*koniec - f(koniec)*poczatek)/(f(poczatek) - f(koniec));;
         int ilosc_krokow = 0;
         while(fabs(f(x)) > EPSILON) {
            x = x - ((2*f(x)*pierwsza_pochodna_f(x)) / (2*pierwsza_pochodna_f(x)*pierwsza_pochodna_f(x) - f(x)*druga_pochodna_f(x)));
            ilosc_krokow++;
         }
         printf("Metoda Newtona dla przedzialu [%.f;%.f] daje miejsce zerowe (w przyblizeniu) %f.\n", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i], x);
         printf("Zrobila to w %d krokach.\n", ilosc_krokow);
      }
   }
}

int main() {
   // nalezy mierzyc kroki wykonania dla kazdej metody, zeby miec porownanie
   double tablica_pocz_przedzialow[3] = {0};
   double tablica_konc_przedzialow[3] = {0};
   szukanie_przedzialow(tablica_pocz_przedzialow, tablica_konc_przedzialow);
   int i;
   printf("Przedzialy w ktorych bedziemy szukac miejsc zerowych:\n");
   for (i=0;i<3;i++) {
      printf("[%f; %f], ", tablica_pocz_przedzialow[i], tablica_konc_przedzialow[i]);
   }
   printf("\n");
   printf("\nwyniki dla METODY BISEKCJI:\n");
   metoda_bisekcji(tablica_pocz_przedzialow, tablica_konc_przedzialow);
   printf("\nwyniki dla METODY REGULA-FALSI:\n");
   metoda_regula_falsi(tablica_pocz_przedzialow, tablica_konc_przedzialow);
   printf("\nwyniki dla METODY SIECZNYCH:\n");
   metoda_siecznych(tablica_pocz_przedzialow, tablica_konc_przedzialow);
   printf("\nwyniki dla METODY NEWTON'A:\n");
   metoda_Newtona(tablica_pocz_przedzialow, tablica_konc_przedzialow);
   printf("\nwyniki dla METODY HALLEY'A:\n");
   metoda_Halleya(tablica_pocz_przedzialow, tablica_konc_przedzialow);
   
   return 0;
}