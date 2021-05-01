//date due matrici calcola la matrice prodotto
#include "..\CN.h"

int main(){
    Matrix *A = prompt_matrix();
    Matrix *B = prompt_matrix();
    Matrix *C = matrix_prod(A, B);

    if(C == NULL)   printf("Matrici non compatibili per il prodotto");
    else            print_matrix(C);
}