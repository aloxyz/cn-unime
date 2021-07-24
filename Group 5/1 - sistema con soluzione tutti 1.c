/* Risolvere un sistema lineare Ax=b con il metodo di Gauss. La matrice A dei coefficienti
deve appartenere ad una delle famiglie di matrici viste nel Gruppo III degli esercizi. La i-
esima componente del vettore b dei termini noti deve essere generato come somma degli
elementi della i-esima riga di A. In tal caso la soluzione è il vettore con tutte le
componenti uguali ad 1. Calcolare l’errore relativo tra la soluzione data dal calcolatore e
la soluzione esatta. Analizzare i risultati ottenuti.
*/

#include "..\systems.h"


#define VECTOR_SUM(MATRIX, VECTOR, TYPE)                                            \
VECTOR->elements.TYPE = malloc(sizeof(*VECTOR->elements.TYPE) * MATRIX->rows);      \
for(int i = 0; i<MATRIX->rows; i++){                                                \
    VECTOR->elements.TYPE[i] = 0;                                                   \
    for(int j = 0; j<MATRIX->cols; j++)                                             \
        VECTOR->elements.TYPE[i] += MATRIX->elements.TYPE[i * MATRIX->cols + j];    \
}

Matrix* vector_sum(Matrix* A){                  //genera un vettore che ha come i-esima componente la somma degli elementi sulla i-esima riga
    Matrix *vec = new_matrix("b", A->rows, 1, A->datatype);

    switch(A->datatype){
        case short_int:     VECTOR_SUM(A, vec, short_int); break;
        case integer:       VECTOR_SUM(A, vec, integer); break;
        case floating:      VECTOR_SUM(A, vec, floating); break;
        case double_prec:   VECTOR_SUM(A, vec, double_prec); break;    
    }
    return vec;
}   

#define VEC_ONES(VEC, N, TYPE)                                  \
    VEC->elements.TYPE = malloc(sizeof(*VEC->elements.TYPE));   \
    for(int i=0; i<N; i++)                                      \
        VEC->elements.TYPE[i] = -1;                              

Matrix *vec_ones(int n, DataType type){         //genera un vettore che abbia tutti gli elementi uguali a -1
    Matrix *tmp = new_matrix("ones", n, 1, type);
    switch(type){
        case short_int:     VEC_ONES(tmp, n, short_int);    break;
        case integer:       VEC_ONES(tmp, n, integer);      break;
        case floating:      VEC_ONES(tmp, n, floating);     break;
        case double_prec:   VEC_ONES(tmp, n, double_prec);  break;        
    }

    return tmp;
}

int main(){

    double range[2];
    Matrix *A, *x, *b, *result;
    int n;
    DataType type;
    printf("Inserisci ordine della matrice\n");
    scanf("%d", &n);
    printf("Inserire l'intervallo in cui variano gli elementi della matrice vettore\n");
    do {
        printf("L'estremo inferiore non puo' essere maggiore di quello superiore\n");
        scanf("%lf %lf", &range[0], &range[1]);
    
    }while (range[0] >= range[1]);


    printf("scegliere tra\n1. short_int\n2. integer\n3. floating\n4. double_prec\n>> ");
    scanf("%d", &type);
    if(type < 1 || type > 4) type = 4; //se il tipo inserito è sbagliato, viene automaticamente selezionato il tipo double

    A = random_matrix(n, n, type, range);
    printf("Risultato calcolato del sistema lineare:\n");
    print_matrix(A);
    b = vector_sum(A);
    print_matrix(b);
    x = gaussian_elimination(A, b);
    print_matrix(x);

    result = vec_ones(n, type);
    printf("L'errore relativo tra il risultato calcolato e quello effettivo e':");
    
    //norma della differenza tra soluzione calcolata e soluzione vera diviso la norma della soluzione vera.
    printf("%e", vec_norm_inf(matrix_sum(x,result), double_prec)->elements.double_prec[0]/vec_norm_inf(result, double_prec)->elements.double_prec[0]);

    return 0;
}