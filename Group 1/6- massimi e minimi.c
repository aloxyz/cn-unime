//Prende n elementi e ne trova il minore o il maggiore

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINMAX(V, FORMAT, TMP, M)           \
scanf(FORMAT, &TMP);                        \
if(M == 'm') {                              \
for(int i = 1; i < size; i++) {             \
    scanf(FORMAT, &V);                      \
    if(V < TMP) TMP = V;                    \
    }                                       \
}                                           \
else {                                      \
for(int i = 1; i < size; i++) {             \
    scanf(FORMAT, &V);                      \
    if(V > TMP) TMP = V;                    \
    }                                       \
                                            \
}                                           \
printf("ans: " FORMAT "\n", TMP); 


int main() {
    union {
        short int short_int;
        int integer;
        float floating;
        double double_prec;
    } v, tmp;

    int t, size;

    printf("scegliere tra\n1. short_int\n2. integer\n3. floating\n4. double_prec\n>> ");
    scanf("%d", &t);
    printf("inserire la lunghezza del vettore\n>>  ");
    scanf("%d", &size);
    
    char c;
    printf("\"m\" o \"M\"\n>> ");
    scanf(" %c", &c);

    if(c != 'm' && c != 'M') {
        printf("%c is invalid, defaulting to max\n", c);
        c = 'M';
    }
    printf("inizializzare il vettore\n>> ");
    if(t <= 1)      {MINMAX(v.short_int, "%hd", tmp.short_int, c)}
    else if(t == 2) {MINMAX(v.integer, "%d", tmp.integer, c)}
    else if(t == 3) {MINMAX(v.floating, "%f", tmp.floating, c)}
    else if(t >= 4) {MINMAX(v.double_prec, "%lf", tmp.double_prec, c)}
}