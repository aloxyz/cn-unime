#include "../CN.h"

int main(){
    Matrix *A, *B, *C;
    A = prompt_matrix();
    B = prompt_matrix();
    C = v_tensor_prod(A,B);
    if(C == NULL) printf("Matrici non compatibili per il prodotto scalare\n");
    else print_matrix(C);

    return 0;
}