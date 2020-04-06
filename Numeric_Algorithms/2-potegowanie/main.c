#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> //gcc -lm
#include <sys/timeb.h>
#include <sys/time.h>

double potegowanie_mnozenie(unsigned long long int potega, double liczba){  //wlasna funkcja potegujaca
    double wynik = liczba;
    while(potega>1) { //petla- dzielimy przez 2 potege dopoki jest wieksza od 1
        wynik *= wynik; //przemnazamy wynik
        potega /= 2;
    }
    return wynik;
}

int main(int argc, char* argv[]) {
    double liczba = atof(argv[1]);
    unsigned long long int potega = (unsigned long long int) atoi(argv[2]);
    
    double wynik_mnozenie, wynik_pow;
    struct timeval startM, endM;    //do mierzenia czasu
    struct timeval startP, endP;
    unsigned long roznicaM, roznicaP;
    
    do {
        int i;
        gettimeofday(&startM, NULL);
        for(i=0;i<100000;i++){
            wynik_mnozenie = potegowanie_mnozenie(potega, liczba);
        }
        gettimeofday(&endM, NULL);
        
        gettimeofday(&startP, NULL);
        for(i=0;i<100000;i++) {
            wynik_pow = pow(liczba, potega);
        }
        gettimeofday(&endP, NULL);
        
        roznicaM = (unsigned long) (1000000 * (endM.tv_sec - startM.tv_sec)) + (endM.tv_usec - startM.tv_usec);
        roznicaP = (unsigned long) (1000000 * (endP.tv_sec - startP.tv_sec)) + (endP.tv_usec - startP.tv_usec);
        printf("%lu   %lu\n", roznicaM, roznicaP);
        printf("obecnie sprawdzana potega: %llu\n", potega);
        potega += 100000;
    } while(roznicaM < roznicaP);   //porownujemy czasy dzialania systemowej pow() i wlasnej funkcji
    
    printf("Mnozenie dziala szybciej od funkcji pow (w przyblizeniu) do %lf.\n", log(potega-200000)/log(2));
    return 0;
}