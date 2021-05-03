#include <stdio.h>
#include <stdlib.h>

#define M_V_PROD(FORMAT, TYPE)\
    v = malloc(sizeof(v->TYPE)*size + sizeof(tmp.TYPE));\
    *A = malloc(sizeof(tmp.TYPE)*(size*size) + sizeof(tmp.TYPE));\
    printf("inizializzare la matrice A\n>> ");\
    for(int i = 0; i < size; i++)\
        for(int j = 0; j < size; j++) scanf(FORMAT, &A[i][j].TYPE);\
    printf("inizializzare il vettore v\n>> ");\
    for(int i = 0; i < size; i++) scanf(FORMAT, &v[i].TYPE);\
    printf("prodotto A·v:\n");\
    printf("( ");\
    int j = 0;\
    for(int i = 0; i < size; i++) {\
        tmp.TYPE = 0;\
        for(j = 0; j < size; j++) tmp.TYPE += A[i][j].TYPE * v[j].TYPE;\
        printf(FORMAT " ", tmp.TYPE);\
    }\
    printf(" )");

int main() {
    union {
        short int short_int;
        int integer;
        float floating;
        double double_prec;
        char *word;
    } *v, **A, tmp;

    int t, size;
    
    printf("scegliere tra\n1. short_int\n2. integer\n3. floating\n4. double_prec\n>> ");
    scanf("%d", &t);
    printf("inserire l'ordine della matrice / lunghezza del vettore\n>>  ");
    scanf("%d", &size);

    if(t == 1) {M_V_PROD("%hd", short_int)} else
    if(t == 3) {M_V_PROD("%f", floating)} else
    if(t == 4) {M_V_PROD("%lf", double_prec)}
    else       {M_V_PROD("%d", integer)}
}