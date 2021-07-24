//calcola la precisione di macchina sia di tipo float che di tipo double per la memoria e l'ALU
#include <stdio.h>
#include <stdlib.h>

#define CALC_PRECISION(SOMMA, EPS)                                             \
  EPS = 1;                                                                     \
  SOMMA = 0;                                                                   \
  do {                                                                         \
    EPS = EPS / 2;                                                             \
    SOMMA = EPS + 1;                                                           \
  } while (SOMMA > 1);                                                         \
                                                                               \
  printf("word precision: %e\n", EPS * 2);                                     \
  EPS = 1;                                                                     \
  do {                                                                         \
    EPS = EPS / 2;                                                             \
  } while (1 + EPS > 1);                                                       \
                                                                               \
  printf("ALU's precision: %e\n", EPS * 2)

int main() {
  typedef union {
    float floating;
    double double_prec;
  } precision;    //utilizzo dell'union per ridurre il numero di variabili esistenti e quindi la memoria utilizzata

  precision somma, eps;
    printf("Precisione singola:\n");
    CALC_PRECISION(somma.floating, eps.floating);
    
    printf("\nPrecisione doppia:\n");
    CALC_PRECISION(somma.double_prec, eps.double_prec);

    return 0;
}