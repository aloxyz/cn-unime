//date due matrici calcola la matrice somma
#include"..\CN.h"

int main(){
    Matrix *A = prompt_matrix();
    Matrix *B = prompt_matrix();
    Matrix *C = matrix_sum(A, B);
    
    if(C == NULL)   printf("Matrici non compatibili per la somma");
    else            print_matrix(C);
    return 0;
}
