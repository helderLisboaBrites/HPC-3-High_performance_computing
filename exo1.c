#include <omp.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    /**
     * Programme qui divise en 4 tâches openMP, chacune affichera son numéro de rang
     * 
     * */
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        int nbr = omp_get_thread_num();
        printf("nombre de thread est %d\n", nbr);
    }
    return 0;
}
