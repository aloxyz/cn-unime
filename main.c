#include "lists.h"

Matrix *head = NULL;
char help_message[BUFSIZ] = "\nUsage:\nn - new matrix\np - print variables\ne - exit\nh - print this message\n";

int main() {

    //default debug matrices

    int v1[] =
    {
        1,2,3,
        4,5,6,
        7,8,9
    };

    short int w1[] =
    {
        1,3,6,
        0,1,6,
        0,0,1
    };

    Pointer v, w;

    v.integer = v1;
    w.short_int = w1;

    Matrix *A = new_matrix("A", 3, 3, integer);
    Matrix *B = new_matrix("B", 3, 3, short_int);
    
    init_elements(A, v);
    init_elements(B, w);

    push_matrix(&head, A);
    push_matrix(&head, B);

    //default debug matrices
/*
    printf("removing %s", B->name);
    remove_matrix(head, "B");
    printf("\n");
    print_list(head);
*/

    char c;
    char cc[16];
    char m1[16];
    char m2[16];
    while(1) {
        printf("\n>> ");
        scanf(" %c", &c);
        switch (c) {
            case 'c':
                printf("\nInsert name of matrix to clone and new one: ");
                scanf("%s %s", m1, m2);
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
            case 's':
                printf("\nsum: ");
                scanf("%s%s", m1, m2);
                matrix_sum(get_matrix(head, m1), get_matrix(head, m2));
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
