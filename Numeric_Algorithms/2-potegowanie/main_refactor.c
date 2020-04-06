#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>  /* compile with -lm flag */
#include <sys/timeb.h>
#include <sys/time.h>

double pow_through_multiply(signed long long int power, double number) {
    double result = number;
    while(power > 1) {
        result *= result;
        power /= 2;
    }
    return wynik;
}

int main(int argc, char* argv[]) {
    double number = atof(argv[1]);
    signed long long int power = (signed long long int) atoi(argv[2]);
    
    double multiplying_result, std_pow_result;
    struct timeval startM, endM;    /* measuring time */
    struct timeval startP, endP;
    unsigned long differenceM, differenceP;
    
    do {
        gettimeofday(&startM, NULL);
        int i;
        for(i=0;i<100000;i++){
            multiplying_result = pow_through_multiply(power, number);
        }
        gettimeofday(&endM, NULL);
        
        gettimeofday(&startP, NULL);
        for(i=0;i<100000;i++) {
            std_pow_result = pow(number, power);
        }
        gettimeofday(&endP, NULL);

        differenceM = (unsigned long) (1000000 * (endM.tv_sec - startM.tv_sec)) + (endM.tv_usec - startM.tv_usec);
        differenceP = (unsigned long) (1000000 * (endP.tv_sec - startP.tv_sec)) + (endP.tv_usec - startP.tv_usec);
        printf("%lu   %lu\n", roznicaM, roznicaP);
        printf("Currently checked power: %llu\n", power);
        power += 100000;
    } while(differenceM < differenceP);   // difference in compute time between functions
    
    printf("Multiplying is working faster than pow: %lf.\n", log(power-200000)/log(2));
    return 0;
}