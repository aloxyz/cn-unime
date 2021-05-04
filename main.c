#include "lists.h"

Matrix *head = NULL;
char help_message[BUFSIZ] = "\nUsage:\nn - new matrix\np - print variables\ne - exit\nh - print this message\n";

int main() {

    //default debug matrices

    short int a1[] =
    {
        1,2,3,
        4,5,6,
        7,8,9
    };

    short int b1[] =
    {
        1,3,6,
        0,1,6,
        0,0,1
    };

    Pointer a, b;

    a.short_int = a1;
    b.short_int = b1;

    Matrix *A = new_matrix("A", 3, 3, short_int);
    Matrix *B = new_matrix("B", 3, 3, short_int);
    
    init_elements(A, a);
    init_elements(B, b);

    push_matrix(&head, A);
    push_matrix(&head, B);

    int vv[] = {1,2,3}; int ww[] = {1,2,3}; Pointer v, w;
    v.integer = vv; Matrix *V = new_matrix("V", 1, 3, integer); init_elements(V, v); push_matrix(&head, V);
    w.integer = ww; Matrix *W = new_matrix("W", 3, 1, integer); init_elements(W, w); push_matrix(&head, W);

    short int small[] = {1,2,3,4,5,6};
    int medium[] = {1,2,3,4,5,6};
    float   floatin[] = {1,2,3,4,5,6};
    double doublem[] = {1,2,3,4,5,6};

    Matrix *C = new_matrix("C", 3, 2, short_int);
    Matrix *D = new_matrix("D", 3, 2, integer);
    Matrix *E = new_matrix("E", 2, 3, floating);
    Matrix *F = new_matrix("F", 2, 3, double_prec);
    
    Pointer small1, medium1, floatin1, doublem1;

    small1.short_int = small;
    medium1.integer = medium;
    floatin1.floating = floatin;
    doublem1.double_prec = doublem;

    init_elements(C, small1);
    init_elements(D, medium1);
    init_elements(E, floatin1);
    init_elements(F, doublem1);

    push_matrix(&head, C);
    push_matrix(&head, D);
    push_matrix(&head, E);
    push_matrix(&head, F);

    //default debug matrices
    print_matrix(v_tensor_prod(V, W));
    print_matrix(v_tensor_prod(V, V));
    print_matrix(v_tensor_prod(W, W));

    //debug

    DataType t;
    char c;
    char cc[16];
    char m1[16];
    char m2[16];
    while(1) {
        printf("\n>> ");
        scanf(" %c", &c);
        switch (c) {
            case 'x':
                scanf("%s%s", m1, m2);
                push_matrix(&head, v_tensor_prod(get_matrix(head, m1), get_matrix(head, m2)));
                print_matrix(get_matrix(head, "ans"));
                break;
            case '^':
                scanf("%s", m1);
                push_matrix(&head, transpose(get_matrix(head, m1)));
                print_matrix(get_matrix(head, "ans"));
                break;
            case '*':
                printf("\nproduct:");
                scanf("%s%s", m1, m2);
                push_matrix(&head, matrix_prod(get_matrix(head, m1), get_matrix(head, m2)));
                print_matrix(get_matrix(head, "ans"));
                break;
            case 't':
                printf("\ntypeconv: ");
                scanf("%s%u", cc, &t);
                matrix_typeconv(get_matrix(head, cc), t);
                break;
            case 'c':
                printf("\nclone: ");
                scanf("%s%s", m1, m2);
                clone_matrix(head, get_matrix(head, m1), m2);
                break;
            case 'r':
                printf("\nremove: ");
                scanf("%s", cc);
                remove_matrix(&head, get_matrix(head, cc));
                printf("\ndone");
                break;
            case 'i':
                printf("\ninfo: ");
                scanf("%s", cc);
                print_info(get_matrix(head, cc));
                break;
            case '+':
                printf("\nsum: ");
                scanf("%s%s", m1, m2);
                push_matrix(&head, matrix_sum(get_matrix(head, m1), get_matrix(head, m2)));
                break;
            case 'n':
                push_matrix(&head, prompt_matrix());
                break;
            case 'p':
                printf("\nprint: ");
                scanf(" %s", cc);
                print_matrix(get_matrix(head, cc));
                break;
            case 'v':
                print_list(head);
                break;
            case 'e':
                return 0;
            case 'h':
                printf("%s", help_message);
                break;
        }
    }
}
