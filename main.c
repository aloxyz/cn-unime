#include "lists.h"

Matrix *head = NULL;
char help_message[BUFSIZ] = "\nUsage:\nn - new matrix\np - print variables\ne - exit\nh - print this message\n";

int main() {
    char c;
    char cc[16];
    while(1) {
        printf("\n>> ");
        scanf(" %c", &c);
        switch (c) {
            case 'n':
                push_matrix(&head, prompt_matrix());
                break;
            case 'p':
                printf("\nvariable name: ");
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
