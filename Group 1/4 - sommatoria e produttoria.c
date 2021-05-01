//dato in input un numero n e n numeri ne calcola la sommatoria e la produttoria
#include <stdio.h>
#include <stdlib.h>

#define SUM_PROD(SUM, PROD, ELEM, FORMAT)                                      \
  SUM = 0;                                                                     \
  PROD = 1;                                                                    \
  for (int i = 0; i < n; i++) {                                                \
    scanf(FORMAT, &ELEM);                                                      \
    SUM += ELEM;                                                               \
    PROD *= ELEM;                                                              \
  }                                                                            \
  printf("Sommatoria:  " FORMAT "\n", SUM);                                    \
  printf("Produttoria: " FORMAT "\n", PROD);


int main() {
  typedef union {
    float floating;
    double double_prec;
  } real;

  int n, choice;
  real sum, prod, elem;

  printf("Inserisci il numero di elementi di cui effettuare produttoria e sommatoria\n");
  scanf("%d", &n);
  printf("Inserire 1 per lavorare in singola precisione, 2 per lavorare in doppia precisione\n");
  scanf("%d", &choice);

  if (choice == 1){
    SUM_PROD(sum.floating, prod.floating, elem.floating, "%f");
  }
  else{
    if (choice != 2)
      printf("Scelta non valida, selezionata la precisione doppia come default");

    SUM_PROD(sum.double_prec, prod.double_prec, elem.double_prec, "%lf");
  }

  return 0;
}