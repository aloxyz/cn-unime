#include "../lists.h"


void ismultiple(Matrix *A) {
    if(A->datatype == integer) {
        if(A->MType == scalar) {
            printf("\n%d", A->elements.integer[0]);
            if(A->elements.integer[0] % 2 == 0) printf(" è pari\n");
            else printf(" è dispari\n");
        } else {
            printf("\n%d", A->elements.integer[0]);
            if(A->elements.integer[0] % A->elements.integer[1] == 0) printf(" è multiplo di ");
            else printf(" non è multiplo di ");
            printf("%d\n", A->elements.integer[1]);
        }
    } else printf("\nnon integral matrix datatype\n");
}

int main() {
    Matrix *head = NULL;

    int v1[] = { 10, 5 };
    Pointer v;
    v.integer = v1;
    Matrix *A = new_matrix("A", 1, 2, integer);
    init_elements(A, v);
    push_matrix(&head, A);
    
    ismultiple(A);
}