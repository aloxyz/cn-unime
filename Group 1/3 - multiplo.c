// programma che dati due numeri A e B, dice se A è pari e se è multiplo di B
#include <stdio.h>
#include <stdlib.h>

#define ISMULTIPLE(FORMAT, TYPE, V, SIZE)                                      \
  if (SIZE == 1) {                                                             \
    V = malloc(sizeof(V[0].TYPE));                                             \
    printf("Inserire il numero: ");                                            \
    scanf(FORMAT, &V[0].TYPE);                                                 \
    if (V[0].TYPE % 2)                                                         \
      printf(FORMAT " e' dispari", V[0].TYPE);                                 \
    else                                                                       \
      printf(FORMAT " e' pari", V[0].TYPE);                                    \
  }                                                                            \
  else{                                                                        \
    V = malloc(sizeof(V[0].TYPE)*2);                                           \
    printf("Inserire il primo e il secondo numero: ");                         \
    scanf(FORMAT FORMAT, &V[0].TYPE, &V[1].TYPE);                              \
                                                                               \
  if (V[0].TYPE % V[1].TYPE)                                                   \
    printf(FORMAT " non e' multiplo di " FORMAT, V[0].TYPE, V[1].TYPE);        \
  else                                                                         \
    printf(FORMAT " e' multiplo di " FORMAT, V[0].TYPE, V[1].TYPE);}

int main() {

  typedef union {
    short short_int;
    int integer;
  } integer;

  integer *V;
  short int choice, size;
  printf("1 per short int (2 byte), 2 per int (4 byte): ");
  scanf("%hd", &choice);
  printf("Inserire 1 per vedere se il numero e' pari, inserire 2 per vedere se "
         "il primo numero e' multiplo del secondo\n");
  scanf("%hd", &size);
if(size != 1 && size != 2) {
  printf("default a 2\n"); 
  size = 2;
  }
  
  if (choice == 1) {
    ISMULTIPLE("%hd", short_int, V, size);
  } else {
    if (choice != 2)
      printf("Numero errato, default a int");
    ISMULTIPLE("%d", integer, V, size);
  }
}
