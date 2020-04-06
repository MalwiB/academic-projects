#include <stdio.h>
#include <math.h>

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

void wyswietlanie_macierzy(double tab[7][7]) {
	int i, j;
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			printf("%.4f ", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void wyswietlanie_wektora(double wektor[7]) {
   int i;
   for(i=0;i<7;i++) {
      printf("%.4f ", wektor[i]);
      printf("\n");
   }
}

int main() {
   //macierz[wiersze][kolumny]
	double macierz[7][7] = {
		{4, 1, 0, 0, 0, 0, 0},
		{1, 4, 1, 0, 0, 0, 0},
		{0, 1, 4, 1, 0, 0, 0},
		{0, 0, 1, 4, 1, 0, 0},
		{0, 0, 0, 1, 4, 1, 0},
		{0, 0, 0, 0, 1, 4, 1},
		{0, 0, 0, 0, 0, 1, 4}
	};
	double wektor_wolnych[7] = {1, 2, 3, 4, 5, 6, 7};
   double wektor_rozwY[7] = {0};    //
   double wektor_rozwX[7] = {0};    // wektor x1, x2, x3... itp.
   
   double macierz_L[7][7] = {0};
   double macierz_LT[7][7] = {0};
   
   printf("Macierz L: \n");
   rozklad_choleskiego(macierz, macierz_L);
   wyswietlanie_macierzy(macierz_L);
   transpozycja(macierz_L, macierz_LT);
   //wyswietlanie_macierzy(macierz_LT);
   
   int i, j;
   wektor_rozwY[0] = wektor_wolnych[0] / macierz_L[0][0];
   for (i=1; i<7; i++) {
      double suma = 0;
      for (j=0; j<i; j++)
         suma += wektor_rozwY[j]  * macierz_L[i][j];
      wektor_rozwY[i] = (wektor_wolnych[i] - suma) / macierz_L[i][i];
   }
   
   printf("wektor_rozwY: \n");
   for (i=0; i<7; i++) {
      printf("%.4f ", wektor_rozwY[i]);
   }
   printf("\n");
   
   wektor_rozwX[6] = wektor_rozwY[6] / macierz_LT[6][6];
   for (i=5; i>=0; i--) {
      double suma = 0;
      for (j=6; j>i; j--)
         suma += wektor_rozwX[j] * macierz_LT[i][j];
      wektor_rozwX[i] = (wektor_rozwY[i] - suma) / macierz_LT[i][i];
   }
   
   printf("Rozwiazanie (wektor_rozwX): \n");
   wyswietlanie_wektora(wektor_rozwX);
   
	return 0;
}