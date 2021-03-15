#include<stdio.h>
#include <omp.h>

#define SOUS_QUESTION6
int main () {
    //omp_set_num_threads(4);
    double t1 = omp_get_wtime();
    static long nb_pas = 1000000000;
    double pas;
    int i; double x, pi, som = 0.0;
    pas = 1.0/(double) nb_pas;
    #ifdef SOUS_QUESTION1
    for (i=0;i< nb_pas; i++){
        x = (i + 0.5)*pas;
        som = som + 4.0/(1.0+x*x);
    }
    #endif


    #ifdef SOUS_QUESTION3
    #pragma omp parallel for reduction(+:som)
    for (i=0;i< nb_pas; i++){
        x = (i + 0.5)*pas;
        som = som + 4.0/(1.0+x*x);
    }
    #endif

    #ifdef SOUS_QUESTION4
    omp_set_num_threads(2);
    #pragma omp parallel for reduction(+:som)
    for (i=0;i< nb_pas; i++){
        x = (i + 0.5)*pas;
        som = som + 4.0/(1.0+x*x);
    }
    #endif

    #ifdef SOUS_QUESTION6
    omp_set_num_threads(3);
    #pragma omp parallel for reduction(+:som)
    for (i=0;i< nb_pas; i++){
        x = (i + 0.5)*pas;
        som = som + 4.0/(1.0+x*x);
    }
    #endif

    pi = pas * som;
    printf("PI=%f\n",pi);
    double t2 = omp_get_wtime();
    printf("Temps Total = %lf\n", t2-t1);
    return 0;
}
