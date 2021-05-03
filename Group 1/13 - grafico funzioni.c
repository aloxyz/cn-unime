//Programma che calcola i punti delle seguenti funzioni
//f(x) = 1/(1+25*x^2) definita in [-1,1]
//f(x) = x/(1+x^2)    definita in [-10,10]   ed in [-1,1]
//f(x) = |x|          definita in [-3.8,4.7] ed in [-2,2]

#include<stdio.h>
#include<math.h>

typedef struct{
    double lower;
    double upper;
}range;

void function1(range D, double step){
    FILE *fp = fopen("dati1", "w");
    for(double x = D.lower, y; x <= D.upper; x+=step){
        y = 1/(1+25*(x*x));
        fprintf(fp, "%lf %lf\n", x, y);
    }
}

void function2(range D, double step){
    FILE *fp = fopen("dati2", "w");
    for(double x = D.lower, y; x <= D.upper; x+=step){
        y = x/(1+(x*x));
        fprintf(fp, "%lf %lf\n", x, y);
    }
}

void function3(range D, double step){
    FILE *fp = fopen("dati3", "w");
    for(double x = D.lower, y; x <= D.upper; x+=step){
        y = fabs(x);
        fprintf(fp, "%lf %lf\n", x, y);
    }
}

int main(){
    range D;
    double step;
    short int choice;
    while(1){
        printf("Inserisci il numero corrispondente alla funzione che vuoi calcolare:\n"
        "1.f(x) = 1/(1+25*x^2)\n"
        "2.f(x) = x/(1+x^2)\n"
        "3.f(x) = |x|\n"
        "0 per uscire\n");
        scanf("%hd", &choice);

        printf("Inserisci l'intervallo in cui calcolare i punti:");
        scanf("%lf%lf", &D.lower, &D.upper);
        printf("Inserisci l'incremento della variabile x: ");
        scanf("%lf", &step);
        if(D.lower > D.upper) printf("L'estremo inferiore non puo' essere piu' grande dell'estremo superiore");
        else{
            switch(choice){
                case 0: return 0;

                case 1:  function1(D, step); break;
                
                case 2:  function2(D, step); break;
                
                case 3:  function3(D, step); break;
                
                default:  printf("Codice non valido");    
            }
        }
    }
    return 0;
}