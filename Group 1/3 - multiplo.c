//programma che dati due numeri A e B, dice se A è pari e se è multiplo di B
#include <stdio.h>

#define ISMULTIPLE(FORMAT, A, B)                                               \
  if (A % 2) printf(FORMAT " e' dispari", A);                                  \
  else       printf(FORMAT " e' pari", A);                                     \
                                                                               \
  if (A % B) printf(" e non e' multiplo di " FORMAT, B);                       \
  else       printf(" ed e' multiplo di " FORMAT, B);

int main() {

  typedef union {
    short short_int;
    int integer;
  } integer;

  integer a, b;
  short int choice;
  printf("1 per short int (2 byte), 2 per int (4 byte): ");
  scanf("%hd", &choice);
  
  if (choice == 1) {
    
    printf("Inserire il primo e il secondo numero: ");
    scanf("%hd%hd", &a.short_int, &b.short_int);
    ISMULTIPLE("%hd", a.short_int, b.short_int)
  } 
  else {
    if (choice != 2)    printf("Numero errato, default a int");
    
    printf("Inserire il primo e il secondo numero: ");
    scanf("%d%d", &a.integer, &b.integer);

    ISMULTIPLE("%d", a.integer, b.integer);
  }
}