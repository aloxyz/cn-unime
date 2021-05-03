#include <stdio.h>
#include <stdlib.h>

#define SCALAR_PROD(FORMAT, TYPE)\
    v = malloc(sizeof(v->TYPE)*size + size);\
    w = malloc(sizeof(w->TYPE)*size + size);\
    printf("inizializzare il vettore 1\n>> ");\
    for(int i = 0; i < size; i++) scanf(FORMAT, &v[i].TYPE);\
    printf("inizializzare il vettore 2\n>> ");\
    for(int i = 0; i < size; i++) scanf(FORMAT, &w[i].TYPE);\
    tmp.TYPE = 0;\
    for(int i = 0; i < size; i++) tmp.TYPE += v[i].TYPE * w[i].TYPE; \
    printf("prodotto scalare: "FORMAT "\n", tmp.TYPE);


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

    if(t == 1) {SCALAR_PROD("%hd", short_int)} else
    if(t == 3) {SCALAR_PROD("%f", floating)} else
    if(t == 4) {SCALAR_PROD("%lf", double_prec)}
    else       {SCALAR_PROD("%d", integer)}
}