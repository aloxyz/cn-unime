//Prende in input n numeri reali o interi e ne fa la media

#include <stdio.h>
#include <stdlib.h>

#define AVERAGE(SUM, FORMAT, X)             \
SUM = 0;                                    \
for(int i = 0; i < size; i++) {             \
    scanf(FORMAT, &X);                      \
    SUM += X;                               \
}                                           \
printf("\nmedia: " FORMAT "\n", SUM/size);  

int main() {
    union {
        short int short_int;
        int integer;
        float floating;
        double double_prec;
    } sum, x;

    int t, size;
    
    printf("scegliere tra\n1. short_int\n2. integer\n3. floating\n4. double_prec\n>> ");
    scanf("%d", &t);
    printf("inserire la lunghezza del vettore\n>>  ");
    scanf("%d", &size);
    printf("inizializzare il vettore\n>> ");

    if(t <= 1)      {AVERAGE(sum.short_int, "%hd", x.short_int)}        //lavora in short se la scelta è minore o uguale a 1
    else if(t == 2) {AVERAGE(sum.integer, "%d", x.integer)}
    else if(t == 3) {AVERAGE(sum.floating, "%f", x.floating)}
    else if(t >= 4) {AVERAGE(sum.double_prec, "%lf", x.double_prec)}    //lavora in double se la scelta è maggiore o uguale a 4

}