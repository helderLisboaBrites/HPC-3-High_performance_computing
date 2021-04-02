/*******************************************************************/ 
/*  HPC(3) : TP4 parallélisation de la solution numérique des Equations
 * aux dérivées partielles, l'équation de la diffusion de la chaleur
 *  
 *  Eva Dokladalova, 2019
 */
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <omp.h>
#include "function.h"
#define QUESTION_1D
#define MOYENNE 1
//-----------------------------------------------------------
// MAIN FUNCTION
//-----------------------------------------------------------
int main (int argc, char *argv[])
{
 
  // noms des fichiers d'entrée et de sortie
  char *filename=argv[1];
  char *file_out=argv[2];
 

  // A COMPLETER SELON LE DERNIER COURS :-)
  #ifdef QUESTION_1D
    
    int tempsTotal = 2;
    float deltaT=0.001;
       
    int size = 1000000;
    double tab[MOYENNE];
    double tab1[MOYENNE];
    double tab2[MOYENNE];
    for(int m=0;m<MOYENNE;m++){
     
    float* u = readFromData(filename, size);
    float* u1 = readFromData(filename, size);
    float* u2 = readFromData(filename, size);
  
    double t1 = omp_get_wtime();
    for(float i = 0; i <= 2; i+=deltaT)
    {
        f_1D(u,deltaT,size);
    }
    double t2 = omp_get_wtime();

    tab[m]=t2-t1;
    

    double  t3 = omp_get_wtime();

    for(float i = 0; i <= 2; i+=deltaT)
    {
        f_1D_deroulage_parallel(u1,deltaT,size);
    }
    
    double t4 = omp_get_wtime();
    tab1[m] = t4-t3;
    printf("Moyenne de temps 1D_déroulage_parallel : %lf \n",t4-t3);

    double  t5 = omp_get_wtime();

    for(float i = 0; i <= 2; i+=deltaT)
    {
        f_1D_parallel(u2,deltaT,size);
    }
    double t6 = omp_get_wtime();

    tab2[m] = t6-t5;

    
  }
  
  double som =0;
  double som1=0;
  double som2=0;

  for(int i=0;i<MOYENNE;i++){
    som+=tab[i];
    som1+=tab1[i];
    som2+=tab2[i];
  }
  printf("Moyenne de temps 1D : %lf \n",som/MOYENNE);
  printf("Moyenne de temps 1D_déroulage_parallel : %lf \n",som1/MOYENNE);
  printf("Moyenne de temps 1D_parallel : %lf \n",som2/MOYENNE);
  #endif


  #ifdef QUESTION_2D

   /** // pointeurs vers les matrices pour l'intégration temporelle
  float *T;
  float **Tdt;
  float *swap;
  // dimension de matrice, valeur maximale
  int v;  // max  value in matrix
  int rw; // row size
  int cl; // column size
  // vérification des arguments d'entrée
  **/
  if (argc != 3)
    {  fprintf(stderr,"Input parameters missing:\n./program_name <inpout.pgm> <output.pgm>\n");
      return(0);
    }
  
  
  //-------------------------------------------------------------
  // OPEN DATA FILE AND ALLOCATE INPUT IMAGE MEMORY (float precision)
  //-------------------------------------------------------------
  T = readimg(filename, &cl, &rw, &v);
  // allocation de 
  Tdt = (float **) calloc (rw,sizeof(float*));
  for(int i = 0; i<rw; i++){ 
    Tdt[i] = calloc(cl, sizeof(float));
    memcpy(Tdt[i],&T[i*cl],sizeof(float)*cl);
    }
  //print_2D_Array(Tdt,rw,cl);
  //-------------------------------------------------------------
  // PUT HERE THE NUMERICAL SOLUTION OF HEAT EQUATION
  // complete variables necessary for for the numerical scheme computing
  //-------------------------------------------------------------
  int i;
  int j;
  int it;
  float dt = 0.01;
  //memcpy(Tdt,T,sizeof(float)*rw*cl);
  //-------------------------------------------------------------
  // WRITE RESULT IN A PGN IMAGE 
  //-------------------------------------------------------------
   float * array =(float*) calloc(rw*cl,sizeof(float));
   for(int i = 0; i<rw; i++){
     memcpy(&array[i*cl],Tdt[i],sizeof(float)*cl);
   }
   /*
   print_2D_Array(Tdt,rw,cl);
   for(int i=0; i<rw; i++){
     for (int j=0; j<cl;j++)
        printf("%.3f, ",array[i*cl+j]);
      printf("\n");
   }
   printf("%d -- %d\n", rw,cl);
   */
   writeimg(file_out, array, cl, rw, v);
   free(Tdt);
   free(T);

   #endif
   
   return(0);
}