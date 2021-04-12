//date due matrici di ordine n calcola la matrice somma: c[i][j]=a[i][j]+b[i][j]

#include<stdio.h>
#include"CN.h"

int main(){
    short int choice;
    int size;
    union tipop A, B, C;
    printf("Inserire l'ordine delle matrici: ");
    scanf("%d", &size);
    printf("Inserire il numero in base al tipo delle matrici con cui vuoi lavorare:\n1 = short int\n2 = int\n3 = float\n4 = double\n");
    scanf("%hd", &choice);
    switch(choice){
        case 1:
                A.shortint = inizializza_matrice_shortint(size);
                B.shortint = inizializza_matrice_shortint(size);
                C.shortint = somma_matrici_shortint(A.shortint , B.shortint, size);    
                stampa_matrice_shortint(A.shortint, size);
                stampa_matrice_shortint(B.shortint, size);
                stampa_matrice_shortint(C.shortint, size);
                break;
        case 2:
                A.intero = inizializza_matrice_int(size);
                B.intero = inizializza_matrice_int(size);
                C.intero = somma_matrici_int(A.intero , B.intero, size);    
                stampa_matrice_int(A.intero, size);
                stampa_matrice_int(B.intero, size);
                stampa_matrice_int(C.intero, size);
                break;
        case 3:
                A.singola = inizializza_matrice_float(size);
                B.singola = inizializza_matrice_float(size);
                C.singola = somma_matrici_float(A.singola , B.singola, size);    
                stampa_matrice_float(A.singola, size);
                stampa_matrice_float(B.singola, size);
                stampa_matrice_float(C.singola, size);
                break;
        case 4:
                A.doppia = inizializza_matrice_double(size);
                B.doppia = inizializza_matrice_double(size);
                C.doppia = somma_matrici_double(A.doppia, B.doppia, size);    
                stampa_matrice_double(A.doppia, size);
                stampa_matrice_double(B.doppia, size);
                stampa_matrice_double(C.doppia, size);
                break;
        default:
                puts("Codice non valido");
    }
    return 0;
}
