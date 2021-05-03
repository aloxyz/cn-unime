#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIALIZE(FORMAT, TYPE)                                               \
  for (int i = 0; i < n; i++)                                                  \
    scanf(FORMAT, &array[i].TYPE);                                             \
  printf("\n\n");

#define BUBBLE_SORT_NUMBERS(TYPE)                                              \
  for (int i = 0, j; i < n; i++) {                                             \
    j = i + 1;                                                                 \
    while (j < n) {                                                            \
      if (array[i].TYPE > array[j].TYPE) {                                     \
        tmp.TYPE = array[j].TYPE;                                              \
        array[j].TYPE = array[i].TYPE;                                         \
        array[i].TYPE = tmp.TYPE;                                              \
      }                                                                        \
      j++;                                                                     \
    }                                                                          \
  }

#define BUBBLE_SORT_STRINGS()                                                  \
  for (int i = 0, j; i < n; i++) {                                             \
    j = i + 1;                                                                 \
    while (j < n) {                                                            \
      if (strcmp(array[i].word, array[j].word) > 0) {                          \
        strcpy(tmp.word, array[j].word);                                       \
        strcpy(array[j].word, array[i].word);                                  \
        strcpy(array[i].word, tmp.word);                                       \
      }                                                                        \
      j++;                                                                     \
    }                                                                          \
  }

#define PRINT_ARRAY(FORMAT, TYPE)                                              \
  for (int i = 0; i < n; i++)                                                  \
    printf(FORMAT "\n", array[i].TYPE);

int main() {
  int n;
  char choice;
  union {
    short int short_int;
    int integer;
    float floating;
    double double_prec;
    char word[BUFSIZ];
  } *array, tmp;

  printf("Quanti elementi vuoi ci siano\?: ");
  scanf("%d", &n);
  printf("1 per short int, 2 per int, 3 per float 4 per double and s per string: ");
  scanf(" %c", &choice);

  if (choice == '1') {
    array = malloc(sizeof(array->short_int) * n);
    INITIALIZE("%hd", short_int);
    BUBBLE_SORT_NUMBERS(short_int);
    PRINT_ARRAY("%hd", short_int);

  } else if (choice == '2') {
    array = malloc(sizeof(array->integer) * n);
    INITIALIZE("%d", integer);
    BUBBLE_SORT_NUMBERS(integer);
    PRINT_ARRAY("%d", integer);

  } else if (choice == '3') {
    array = malloc(sizeof(array->floating) * n);
    INITIALIZE("%f", floating);
    BUBBLE_SORT_NUMBERS(floating);
    PRINT_ARRAY("%.10f", floating);
  
  } else if (choice == 's') {
    
    array = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
      scanf("%s", array[i].word);
    }
    printf("\n\n");
    
    BUBBLE_SORT_STRINGS()
    PRINT_ARRAY("%s", word);
  
  } else {
    if (choice != '4')
      printf("Scelta non valida, selezionata la precisione doppia come "
             "default.\n");
    array = malloc(sizeof(array->double_prec) * n);
    INITIALIZE("%lf", double_prec);
    BUBBLE_SORT_NUMBERS(double_prec);
    PRINT_ARRAY("%.16lf", double_prec);
  }
  return 0;
}