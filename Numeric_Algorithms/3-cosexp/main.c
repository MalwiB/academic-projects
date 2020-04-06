#include <stdio.h>
#include <math.h>

double metoda_wolna (int N, double x) {
    double wynik=0;
    int i;
    for(i=1; i<=N; i++) {
        wynik+=(cos(i*x)*exp(-i));
    }
    return wynik;
}

double metoda_zoptymalizowana(int N, double x) { //moze istniec pewien blad, ktory nalezy zbadac i musi byc mniejszy od EPSILON
    //ustawienia poczatkowe:
    double exp_minus_1 = exp(-1);
    double wynik = 0;
    double exp_n = exp_minus_1;
    double cos_x = cos(x);
    double cos_minus = 1;
    double cos_minus2 = cos_x;
    
    double cosinus_n_x;
    int n;
    for(n=1;n<=N;n++) {
        cosinus_n_x = (2. * cos_minus * cos_x) - cos_minus2;
        wynik += cosinus_n_x * exp_n;
        exp_n = exp_n*exp_minus_1;
        cos_minus2 = cos_minus;
        cos_minus = cosinus_n_x;
    }
    
    return wynik;
}

int main(int argc, char*argv[]) {
    double wynik_wolna, wynik_zoptymalizowana;
    int N = 30;  //wstepnie ustalamy sobie ilosc sumowan
    const double x = 0.2;
    double roznica = 1;
    wynik_wolna = metoda_wolna(N, x);
    N = 0;
    do {
        N++;    //zwiekszamy ilosc sumowan
        wynik_zoptymalizowana = metoda_zoptymalizowana(N, x);
        printf("wynik wolna: %.12lf, wynik_zoptymalizowana: %.12lf\n", wynik_wolna, wynik_zoptymalizowana);
        roznica = fabs(wynik_wolna-wynik_zoptymalizowana);
    } while ( roznica > 1.0E-10);
    
    printf("dla N: %d wynik: %.12lf(wolna metoda), a %.12lf(metoda zoptymalizowana).\n", N, wynik_wolna, wynik_zoptymalizowana);
    return 0;
}
