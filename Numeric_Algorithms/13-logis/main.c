#include <stdio.h>
#include <stdlib.h>

// odwzorowanie logistyczne to funkcja: x = k*x(1-x)
double odwzorowanie(double k, double x) {
   double wynik = k*x*(1-x);
   return wynik;
}

int main() {
   //tworzymy plik .dat i otwieramy do pisania
   FILE* dane = fopen("dane.dat", "w");
   if(dane == NULL) {
      printf("Nie mozna otworzyc pliku!\n");
      exit(1);
   }
   
   // w tym przypadku mamy narysowac wykres dla k nalezacego do przedzialu [2;4]
   // x musi byc wiekszy od 100
   double x=0.5, k;
   int n;
   for(k=2;k<=4;k+=1e-3) {
      for(n=100;n<600;n+=1e1) {
         char linijka[20];
         // wypisujemy k oraz x, bo dla tych wartosci bedziemy rysowac w gnuplocie wykres zaleznosci
         x = odwzorowanie(k, x);
         sprintf(linijka, "%f %f\n", k, x);
         fputs(linijka, dane);
      }
   }
   
   fclose(dane);
   return 0;
}