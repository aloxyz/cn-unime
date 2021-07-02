/* Considerare vettori con un numero n di componenti da 2 a 20, le cui componenti sono
   punti equidistanti dell'intervallo [-1,1], oppure un intervallo [a,b] con a e b numeri reali.
   Calcolare le tre norme vettoriali al crescere di n e farne il confronto analizzando il grafico dei risultati
*/

#include "..\CN.h"
#include <stdio.h>

#define PRINT_TO_FILE(FORMAT,  TYPE)                                                        \
    while(range_dimension[0] <= range_dimension[1]){\
        vector = random_matrix(1, range_dimension[0], TYPE, range_elements);                \
        print_matrix(vector); \
        fprintf(uno, "%d " FORMAT, range_dimension[0], norm1(vector, TYPE)->elements.TYPE[0]);\
        fprintf(due, "%d " FORMAT, range_dimension[0], norm2(vector, TYPE)->elements.TYPE[0]);\
        fprintf(inf, "%d " FORMAT, range_dimension[0], norm_inf(vector, TYPE)->elements.TYPE[0]);\
\
        range_dimension[0]++;\
        free(vector);        \
    }


int main(){
    double range_elements[2];
    int range_dimension[2];

    Matrix *vector;
    DataType type;
    FILE *uno = fopen("norma 1", "w");
    FILE *due = fopen("norma 2", "w");
    FILE *inf = fopen("norma inf", "w");

    printf("Inserire l'intervallo in cui variano gli elementi di ogni vettore\n");
    do {
        printf("L'estremo inferiore non puo' essere maggiore di quello superiore\n");
        scanf("%lf %lf", &range_elements[0], &range_elements[1]);
    
    }while (range_elements[0] >= range_elements[1]);


    printf("Inserire l'intervallo in cui varia il numero delle componenti dei vettori.\n");
    do {
        printf("L'estremo inferiore non puo' essere maggiore di quello superiore e nemmeno negativo\n");
        scanf("%d %d", &range_dimension[0], &range_dimension[1]);
    
    }while (range_dimension[0] >= range_dimension[1]);

    printf("scegliere tra\n1. short_int\n2. integer\n3. floating\n4. double_prec\n>> ");
    scanf("%d", &type);
    if(type < 1 || type > 4) type = 1;

    switch(type){

        case 1: PRINT_TO_FILE("%hd\n", short_int);
        case 2: PRINT_TO_FILE("%d\n", integer);
        case 3: PRINT_TO_FILE("%f\n", floating);
        case 4: PRINT_TO_FILE("%lf\n", double_prec);

    }
    
    return 0;
}
