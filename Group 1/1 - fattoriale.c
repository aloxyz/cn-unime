#include <stdio.h>
#include <stdlib.h>

#define FACT(N, TYPE, FORMAT1, FORMAT2)   \
    printf("\n");   \
    printf(FORMAT1, N);   \
    while(N < max) {   \
        TYPE tmp = N;   \
        for(int i = N - 1; i >= 2; i--) {   \
            tmp *= i;   \
        }   \
        printf(FORMAT2, N, tmp);   \
        N++;   \
    }


int main(int argc, char **argv) {

    int x = atoi(argv[1]);
    float y = atof(argv[2]);
    double z = atof(argv[3]);
    int max = atoi(argv[4]);

    printf("max: %d\n-------", max);

    FACT(x, int,    "\nint %d:\n\n",        "%d! = %d\n");
    FACT(y, float,  "\nfloat %.2f:\n\n",    "%.2f! = %.2f\n");
    FACT(z, double, "\ndouble %.4lf:\n\n",  "%.4lf! = %.4lf\n");
    
}