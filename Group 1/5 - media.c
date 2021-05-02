#include <stdio.h>
#include <stdlib.h>

#define AVERAGE(SUM, FORMAT, X)\
SUM = 0;\
for(int i = 0; i < size; i++) {\
    scanf(FORMAT, &X);\
    SUM += X;\
}\
printf("\nmedia: " FORMAT "\n", SUM/size);\

int main() {
    union {
        short int short_int;
        int integer;
        float floating;
        double double_prec;
        char *word;
    } v, x;

    int t, size;
    
    printf("scegliere tra\n1. short_int\n2. integer\n3. floating\n4. double_prec\n>> ");
    scanf("%d", &t);
    printf("inserire la lunghezza del vettore\n>>  ");
    scanf("%d", &size);
    printf("inizializzare il vettore\n>> ");

    if(t <= 1)      {AVERAGE(v.short_int, "%hd", x.short_int)}
    else if(t == 2) {AVERAGE(v.integer, "%d", x.integer)}
    else if(t == 3) {AVERAGE(v.floating, "%f", x.floating)}
    else if(t >= 4) {AVERAGE(v.double_prec, "%lf", x.double_prec)}

}