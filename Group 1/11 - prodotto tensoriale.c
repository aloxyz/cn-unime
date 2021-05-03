#include <stdio.h>
#include <stdlib.h>

#define TENSOR_PROD(FORMAT, TYPE)\
    v = malloc(sizeof(v->TYPE)*size + sizeof(tmp.TYPE));\
    w = malloc(sizeof(w->TYPE)*size + sizeof(tmp.TYPE));\
    printf("inizializzare il vettore 1\n>> ");\
    for(int i = 0; i < size; i++) scanf(FORMAT, &v[i].TYPE);\
    printf("inizializzare il vettore 2\n>> ");\
    for(int i = 0; i < size; i++) scanf(FORMAT, &w[i].TYPE);\
    printf("prodotto tensoriale:\n");\
    printf("( ");\
    for(int i = 0; i < size; i++)\
        for(int j = 0; j < size; j++) printf(FORMAT " ", v[i].TYPE * w[j].TYPE);\
    printf(" )");

int main() {
    union {
        short int short_int;
        int integer;
        float floating;
        double double_prec;
        char *word;
    } *v, *w, tmp;

    int t, size;
    
    printf("scegliere tra\n1. short_int\n2. integer\n3. floating\n4. double_prec\n>> ");
    scanf("%d", &t);
    printf("inserire la lunghezza dei vettori\n>>  ");
    scanf("%d", &size);

    if(t == 1) {TENSOR_PROD("%hd", short_int)} else
    if(t == 3) {TENSOR_PROD("%f", floating)} else
    if(t == 4) {TENSOR_PROD("%lf", double_prec)}
    else       {TENSOR_PROD("%d", integer)}
}