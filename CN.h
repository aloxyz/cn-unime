union tipop{     //matrice o vettore di tipo sconosciuto
    short int   *shortint;
    int         *intero;
    float       *singola;
    double      *doppia;
    };
union tipos{     //scalari di tipo sconosciuto
    short int   shortint;
    int         intero;
    float       singola;
    double      doppia;
    };

//Operazioni di tipo short int
//Matrici
short int *inizializza_matrice_shortint(int size);                                              //inizializza matrice di ordine size
short int *somma_matrici_shortint(short int A[], short int B[], int size);                      //somma due matrici A + B = C
void stampa_matrice_shortint(short int Matrice[], int size);                                    //stampa una matrice di ordine size
//Vettori
short int *inizializza_array_shortint(int size);                                                //inizializza un array di ordine size
short int prodotto_scalare_shortint(short int arrayA[], short int arrayB[], int size);          //effettua il prodotto scalare tra due vettori
short int *prodotto_tensoriale_shortint(short int arrayA[], short int arrayB[], int size);      //effettua il prodotto tensoriale tra due vettori
void stampa_array_shortint(short int array[], int size);                                        //stampa un array di ordine size


//Operazioni di tipo int
//Matrici
int *inizializza_matrice_int(int size); 
int *somma_matrici_int(int A[], int B[], int size); 
void stampa_matrice_int(int Matrice[], int size);
//Vettori
int fact(int m);
int fact_plus(int x, float y, double z, int max);
int int_sum(int *v, int n);
int int_prod(int *v, int n);
int int_avg(int *v, int n);
int int_min(int *v, int n);
int int_max(int *v, int n);
int int_sort(int *v, int n);

int *inizializza_array_int(int size); 
int prodotto_scalare_int(int arrayA[], int arrayB[], int size);
int *prodotto_tensoriale_int(int arrayA[], int arrayB[], int size); 
void stampa_array_int(int array[], int size);


//Operazioni di tipo float
//Matrici
float *inizializza_matrice_float(int size); 
float *somma_matrici_float(float A[], float B[], int size); 
void stampa_matrice_float(float Matrice[], int size);
//Vettori
float *inizializza_array_float(int size); 
float prodotto_scalare_float(float arrayA[], float arrayB[], int size);
float *prodotto_tensoriale_float(float arrayA[], float arrayB[], int size); 
void stampa_array_float(float array[], int size);


//Operazioni di tipo double
//Matrici
double *inizializza_matrice_double(int size); 
double *somma_matrici_double(double A[], double B[], int size); 
void stampa_matrice_double(double Matrice[], int size);
//Vettori
double double_sum(double *v, int n);
double double_avg(double *v, int n);

double *inizializza_array_double(int size); 
double prodotto_scalare_double(double arrayA[], double arrayB[], int size);
double *prodotto_tensoriale_double(double arrayA[], double arrayB[], int size); 
void stampa_array_double(double array[], int size);
