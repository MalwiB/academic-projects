#include <stdio.h>
#include <math.h>

//funkcje- dzialania na wektorach
double wektor_T_wektor(double wektor[7], double wektor2[7]) {
   int i; double suma=0;
   for(i=0;i<7;i++) {
      suma += wektor[i]*wektor2[i];
   }
   return suma;
}

void odejmowanie_wektorow(double wektor[7], double wektor_odejmowany[7], double wektor_do_zapisu[7]) {
   int i;
   for(i=0;i<7;i++) {
      wektor_do_zapisu[i] = wektor[i] - wektor_odejmowany[i];
   }
}

void liczba_wektor(double a, double wektor[7], double wektor_do_zapisu[7]) {
   int i;
   for(i=0;i<7;i++){
      wektor_do_zapisu[i] = a*wektor[i];
   }
}

//funkcje do wykonania rozkladu, przyspieszenie rozwiazania rownan
void transpozycja(double macierz[7][7], double macierz_do_zapisu[7][7]) {
   int i, j;
   for(i=0;i<7;i++) {
      for(j=0;j<7;j++)
         macierz_do_zapisu[j][i] = macierz[i][j];
   }
}

void rozklad_choleskiego(double macierz[7][7], double macierz_L[7][7]) {
   int i, k, j;
   for(i = 0; i< 7;i++) {
      for(k = 0; k < (i+1); k++){
         double suma = 0;
         for(j = 0; j < k; j++){
            suma += macierz_L[i][j] * macierz_L[k][j];
         }
         macierz_L[i][k] =  (i == k) ? (sqrt(macierz[i][i] - suma)) : ((1.0 / macierz_L[k][k] * (macierz[i][k] - suma)));
      }
   }
}

int main() {
   double macierz[7][7] = {
      {4, 1, 0, 0, 0, 0, 1},
      {1, 4, 1, 0, 0, 0, 0},
      {0, 1, 4, 1, 0, 0, 0},
      {0, 0, 1, 4, 1, 0, 0},
      {0, 0, 0, 1, 4, 1, 0},
      {0, 0, 0, 0, 1, 4, 1},
      {1, 0, 0, 0, 0, 1, 4}
   };
   double u[7] = { 1, 0, 0, 0, 0, 0, 0 };
   double vT[7] = { 1, 0, 0, 0, 0, 0, 0 };
   double wektor_wolnych[7] = {1,2,3,4,5,6,7};
   
   double z[7] = {0};   // bedzie potrzebny przy: A*z = wektor_wolnych
   double q[7] = {0};   // A*q = u
   double w[7] = {0};   // wektor w ktorym znajdzie sie wynik
   
   // najpierw rozwiazujemy powyzsze rownania:
   double macierz_L[7][7] = {0};
   double macierz_LT[7][7] = {0};
   rozklad_choleskiego(macierz, macierz_L);
   transpozycja(macierz_L, macierz_LT);
   
   // mamy juz rozklad macierzy, teraz znalezienie rozwiazan nie jest zbyt kosztowne
   // rozwiazujemy najpierw macierz*z = wektor_wolnych
   double wektor_rozwY[7] = {0};
   int i, j;
   wektor_rozwY[0] = wektor_wolnych[0] / macierz_L[0][0];
   for (i=1; i<7; i++) {
      double suma = 0;
      for (j=0; j<i; j++)
         suma += wektor_rozwY[j]  * macierz_L[i][j];
      wektor_rozwY[i] = (wektor_wolnych[i] - suma) / macierz_L[i][i];
   }
   z[6] = wektor_rozwY[6] / macierz_LT[6][6];
   for (i=5; i>=0; i--) {
      double suma = 0;
      for (j=6; j>i; j--)
         suma += z[j] * macierz_LT[i][j];
      z[i] = (wektor_rozwY[i] - suma) / macierz_LT[i][i];
   }
   // rozwiazujemy macierz*q = u
   wektor_rozwY[0] = u[0] / macierz_L[0][0];
   for (i=1; i<7; i++) {
      double suma = 0;
      for (j=0; j<i; j++)
         suma += wektor_rozwY[j]  * macierz_L[i][j];
      wektor_rozwY[i] = (u[i] - suma) / macierz_L[i][i];
   }
   q[6] = wektor_rozwY[6] / macierz_LT[6][6];
   for (i=5; i>=0; i--) {
      double suma = 0;
      for (j=6; j>i; j--)
         suma += q[j] * macierz_LT[i][j];
      q[i] = (wektor_rozwY[i] - suma) / macierz_LT[i][i];
   }
   
   
   // teraz stosujemy wzor Shermana-Morrisona:
   
   //vTz = vT*z
   double vTz = wektor_T_wektor(vT, z);
   double vTq = wektor_T_wektor(vT, q);
   
   vTq = vTq +1;
   double iloraz = vTz/vTq;
   double iloraz_q[7] = {0};
   liczba_wektor(iloraz, q, iloraz_q);
   odejmowanie_wektorow(z, iloraz_q, w);
   
   //wypisujemy wynik
   for(i=0;i<7;i++)
      printf("%.4f ", w[i]);
   printf("\n");
   
	return 0;
}