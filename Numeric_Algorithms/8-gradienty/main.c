#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void odejmowanie_wektorow(double wektor[3], double wektor_odejmowany[3], double wektor_do_zapisu[3]) {
   int i;
   for(i=0;i<3;i++) {
      wektor_do_zapisu[i] = wektor[i] - wektor_odejmowany[i];
   }
}

void dodawanie_wektorow(double wektor[3], double wektor2[3], double wektor_do_zapisu[3]) {
   int i;
   for(i=0;i<3;i++) {
      wektor_do_zapisu[i] = wektor[i] + wektor2[i];
   }
}

void liczba_wektor(double a, double wektor[3], double wektor_do_zapisu[3]) {
   int i;
   for(i=0;i<3;i++){
      wektor_do_zapisu[i] = a*wektor[i];
   }
}

void mnozenie_macierz_wektor(double tab[3][3], double wektor[3], double wektor_do_zapisu[3]) {
   int i, j;
   for(i=0;i<3;i++) {
      wektor_do_zapisu[i] = 0;
   }
   for(i=0;i<3;i++) {
      for(j=0;j<3;j++) {  //macierz[wiersze][kolumny]
         wektor_do_zapisu[i] += tab[j][i]*wektor[j];
      }
   }
}

double wektor_T_wektor(double wektor[3], double wektor2[3]) {
   int i; double suma=0;
   for(i=0;i<3;i++) {
      suma += wektor[i]*wektor2[i];
   }
   return suma;
}

double norma(double wektor[3]) {
   double suma_kwadratow=0, norma=0;
   int i;
   for(i=0;i<3;i++) {
      suma_kwadratow += wektor[i]*wektor[i];
   }
   norma = sqrt(suma_kwadratow);
   return norma;
}


double main() {
   int i;
   //macierz[wiersze][kolumny]
   double macierz[3][3] = {
      {4, -1, 0},
      {-1, 4, -1},
      {0, -1, 4}
   };
   double wektor_rozw[3] = {2, 6, 2};
   double x1[3] = {40000, 043, 9999};	//poczatkowe przyblizenie rozwiazania rownania
   
   //A*x1
   double temp_wektor[3];
   mnozenie_macierz_wektor(macierz, x1, temp_wektor);
   
   //r = b - A*x1;
   double r[3];
   odejmowanie_wektorow(wektor_rozw, temp_wektor, r);
   
   //p = r     ==   p1 = r1 
   double p[3];
   memcpy(p, r, sizeof(double)*3);
   
   //x = x1;
   double x[3];
   memcpy(x, x1, sizeof(double)*3);
   
   //inicjalizacja uzywanych w petli wektorow i zmiennych
   double p_plus_1[3];
   double r_plus_1[3];
   double Ap[3];
   double alfa_Ap[3];
   double beta_p[3];
   double alfa_p[3];
   double alfa, beta;
   int licznik;
   const double EPSILON = 0.0000003;
   do {
      mnozenie_macierz_wektor(macierz, p, Ap); //wyliczenie Ap
      alfa = wektor_T_wektor(r, r)/wektor_T_wektor(p, Ap);
      liczba_wektor(alfa, Ap, alfa_Ap);
      odejmowanie_wektorow(r, alfa_Ap, r_plus_1);
      beta = wektor_T_wektor(r_plus_1, r_plus_1)/wektor_T_wektor(r, r);
      liczba_wektor(beta, p, beta_p);
      dodawanie_wektorow(r_plus_1, beta_p, p_plus_1);
      liczba_wektor(alfa, p, alfa_p);
      dodawanie_wektorow(x, alfa_p, x);
      licznik++;
      
      memcpy(p, p_plus_1, sizeof(double) * 3);
      memcpy(r, r_plus_1, sizeof(double) * 3);
      
   } while(norma(r_plus_1) > EPSILON);
   
   printf("Przyblizone rozwiazanie to: ");
   for(i=0;i<3;i++)
      printf("%f ", x[i]);
   printf("\nOsiagnieto to po %d iteracjach.\n", licznik);
   
   return 0;
}