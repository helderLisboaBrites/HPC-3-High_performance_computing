#include <omp.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    /**
     * Programme teste les Variables privées
     * 
     * */
    omp_set_num_threads(4);
    int VALEUR1 = 1000;
    int VALEUR2 = 2000;

    #pragma omp parallel firstprivate(VALEUR2)
    {
        VALEUR2 ++;
        printf("VALEUR1 = %d\n", VALEUR1);
        printf("VALEUR2 = %d\n", VALEUR2);
    }
    return 0;
}
