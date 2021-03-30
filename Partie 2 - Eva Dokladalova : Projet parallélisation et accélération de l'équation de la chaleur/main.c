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
#include "omp.h"
#include "function.h"

//-----------------------------------------------------------
// MAIN FUNCTION
//-----------------------------------------------------------
int main (int argc, char *argv[])
{
 

  // noms des fichiers d'entrée et de sortie
  char *filename=argv[1];
  char *file_out=argv[2];

  // pointeurs vers les matrices pour l'intégration temporelle
  float *T;
  float **Tdt;
  float *swap;

  // dimension de matrice, valeur maximale
  int v;  // max  value in matrix
  int rw; // row size
  int cl; // column size

  // vérification des arguments d'entrée
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

  double  t0 = omp_get_wtime();     

  // A COMPLETER SELON LE DERNIER COURS :-)

    
    int tempsTotal = 2;
    float deltaT=0.001;
       /*
           int size = 100000;
    float* u = readFromData(filename, size);
    float* u1 = readFromData(filename, size);
    for(float i = 0; i <= 2; i+=deltaT)
    {
        f_1D(u,deltaT,size);
    }


    //print tableau valeurs
    //printArray(u,size);
    

    
    double  t1 = omp_get_wtime();
    double  temps_reel=t1-t0;
    printf( " temps  reel : %lf \n", temps_reel);

    t0 = omp_get_wtime();     

    for(float i = 0; i <= 2; i+=deltaT)
    {
        f_1D_parallele(u1,deltaT,size);
    }

    //print tableau valeurs
    //printArray(u,size);

   
    t1 = omp_get_wtime ();
    temps_reel=t1-t0;
    printf( " temps  reel : %lf \n", temps_reel);

     size=10;
    float** u_tmp = (float**) calloc(size, sizeof(float*));
    for(int i = 0; i<size; i++) u_tmp[i] = calloc(size, sizeof(float));
    int moit =(int)size/2;
    u_tmp[moit][moit]=255;
    print_2D_Array(u_tmp,size,size);
    for(float i = 0; i <= 2; i+=deltaT)
    {
      f_2D(u_tmp,deltaT,size,size);
    }
    print_2D_Array(u_tmp,size,size);

    */

    for(float i = 0; i <= 5; i+=deltaT)
    {
      f_2D(Tdt,deltaT,rw,cl);
    }
    //print_2D_Array(Tdt,rw,cl);


  
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
   
   return(0);
}