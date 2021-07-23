#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WRAPPER(FORMAT, TYPE)                                                   \
    array = malloc(sizeof(array->TYPE) * n);                                    \
    INITIALIZE(FORMAT, TYPE);                                                   \
    BUBBLE_SORT_NUMBERS(TYPE);                                                  \
    PRINT_ARRAY(FORMAT, TYPE);

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

switch(choice){
  case 's': array = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
      scanf("%s", array[i].word);
    }
    printf("\n\n");
    
    BUBBLE_SORT_STRINGS()
    PRINT_ARRAY("%s", word);
    break;

  case '1':     WRAPPER("%hd", short_int); break;
  case '2':     WRAPPER("%d", integer); break;
  case '3':     WRAPPER("%f", floating); break;
  
  default:      if (choice != '4')
                printf("Scelta non valida, selezionata la precisione doppia come "
                "default.\n");      
                WRAPPER("%lf", double_prec); break;
}
  return 0;
}