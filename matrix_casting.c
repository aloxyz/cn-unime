#include "lists.h" 

#define GENERATE_CONVERT(FROM, TO)                                             \
  void matrix_typeconv_##FROM##_##TO(Matrix *A) {                              \
    Pointer tmp;                                                               \
    tmp.FROM = malloc(sizeof(*tmp.FROM) * size(A));                             \
    for (int i = 0; i < size(A); i++)                                          \
      tmp.FROM[i] = A->elements.FROM[i];                                       \
                                                                               \
    A->elements.TO = malloc(sizeof(*A->elements.TO) * size(A));                \
    for (int i = 0; i < size(A); i++)                                          \
      A->elements.TO[i] = tmp.FROM[i];                                         \
    free(tmp.FROM);                                                            \
    A->datatype = TO;                                                          \
  }

#define DEFINE_CONVERSIONS(TYPE)                                               \
  GENERATE_CONVERT(TYPE, short_int)                                            \
  GENERATE_CONVERT(TYPE, integer)                                              \
  GENERATE_CONVERT(TYPE, floating)                                             \
  GENERATE_CONVERT(TYPE, double_prec)

DEFINE_CONVERSIONS(short_int)
DEFINE_CONVERSIONS(integer)
DEFINE_CONVERSIONS(floating)
DEFINE_CONVERSIONS(double_prec)

#define CONVERT(NAME, TO)                                                      \
  switch (TO) {                                                                \
                                                                               \
  case short_int:                                                              \
    switch (NAME->datatype) {                                                  \
    case short_int:                                                            \
      break;                                                                   \
    case integer:                                                              \
      matrix_typeconv_integer_short_int(NAME);                                 \
      break;                                                                   \
    case floating:                                                             \
      matrix_typeconv_floating_short_int(NAME);                                \
      break;                                                                   \
    case double_prec:                                                          \
      matrix_typeconv_double_prec_short_int(NAME);                             \
    }                                                                          \
    break;                                                                     \
                                                                               \
  case integer:                                                                \
    switch (NAME->datatype) {                                                  \
    case short_int:                                                            \
      matrix_typeconv_short_int_integer(NAME);                                 \
      break;                                                                   \
    case integer:                                                              \
      break;                                                                   \
    case floating:                                                             \
      matrix_typeconv_floating_integer(NAME);                                  \
      break;                                                                   \
    case double_prec:                                                          \
      matrix_typeconv_double_prec_integer(NAME);                               \
    }                                                                          \
    break;                                                                     \
  case floating:                                                               \
    switch (NAME->datatype) {                                                  \
    case short_int:                                                            \
      matrix_typeconv_short_int_floating(NAME);                                \
      break;                                                                   \
    case integer:                                                              \
      matrix_typeconv_integer_floating(NAME);                                  \
      break;                                                                   \
    case floating:                                                             \
      break;                                                                   \
    case double_prec:                                                          \
      matrix_typeconv_double_prec_floating(NAME);                              \
    }                                                                          \
    break;                                                                     \
  case double_prec:                                                            \
    switch (NAME->datatype) {                                                  \
    case short_int:                                                            \
      matrix_typeconv_short_int_double_prec(NAME);                             \
      break;                                                                   \
    case integer:                                                              \
      matrix_typeconv_integer_double_prec(NAME);                               \
      break;                                                                   \
    case floating:                                                             \
      matrix_typeconv_floating_double_prec(NAME);                              \
      break;                                                                   \
    case double_prec:                                                          \
      break;                                                                   \
    }                                                                          \
    break;                                                                     \
  }                                                                            \
