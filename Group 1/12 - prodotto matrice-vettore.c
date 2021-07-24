//Dati una matrice A di ordine n ed un vettore x di n componenti calcolare Ax e xT A.
#include "..\CN.h"

int main(){
  
    
    Matrix *A, *B, *C;

    A = prompt_matrix();
    B = prompt_matrix();
    printf("Prodotto tra %s e %s\n", A->name, B->name);
    C = matrix_prod(A, B);
    if(C == NULL) printf("Matrici non compatibili per essere moltiplicate\n");
    else print_matrix(C);

    printf("Prodotto tra %s trasposta e %s\n", B->name, A->name);

    C = matrix_prod(transpose(B), A); 
    if(C == NULL) printf("Matrici non compatibili per essere moltiplicate\n");
    else print_matrix(C);    return 0;

}