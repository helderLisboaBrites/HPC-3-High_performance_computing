#include <omp.h>
#include <stdio.h>
#define FOR_PARA

int main(int argc, char const *argv[])
{
    /**
     * Ecrire un programme qui compte de 1 à 50 en utilisant une simple boucle, et fait un printf du
     * compteur à chaque itération.
     * 
     * */
    
    omp_set_num_threads(8);
    #ifdef FOR_PARA1
    for(int i = 1 ; i <= 50; i++ ){
        printf("Valeur i = %d\n",i);
    }
    #endif

    #ifdef FOR_PARA
    #pragma omp parallel for
             
    for(int i = 1 ; i <= 50; i++ ){
        int nbr = omp_get_thread_num();
        printf("Thread n = %d | Valeur i = %d\n",nbr,i);
    }
    
    #endif

    return 0;
}
