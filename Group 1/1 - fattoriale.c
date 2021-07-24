//dato un numero n calcola tutti i fattoriali da 2 a n, per i tipi int float e double
#include <stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {   //numero da inserire come argomento del programma chiamato

    int max = atoi(argv[1]);
    int fac_int=1;
    float fac_float=1;
    double fac_double=1;

    for(int i=2; i<=max; i++){
        printf("Fac %d:\n", i);
        printf("int:    %d\n", fac_int = fac_int*i);
        printf("float:  %f\n", fac_float = fac_float*i);
        printf("double: %lf\n", fac_double = fac_double*i);
    }

    return 0;
}