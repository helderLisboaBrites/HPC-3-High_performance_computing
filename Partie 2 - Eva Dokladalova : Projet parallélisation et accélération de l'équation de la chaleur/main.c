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
  float *Tdt;
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
  //T = readimg(filename, &rw, &cl, &v);
  //Tdt = (float *) calloc (rw*cl,sizeof(float));

  //-------------------------------------------------------------
  // PUT HERE THE NUMERICAL SOLUTION OF HEAT EQUATION
  // complete variables necessary for for the numerical scheme computing
  //-------------------------------------------------------------
  int i;
  int j;
  int it;
  float dt = 0.01;
  memcpy(Tdt,T,sizeof(float)*rw*cl);
   
  double  t0 = omp_get_wtime();     

  // A COMPLETER SELON LE DERNIER COURS :-)
    int size = 100000;
    float* u = readFromData(filename, size);
    float* u1 = readFromData(filename, size);
    
    int tempsTotal = 2;
    float deltaT=0.001;
    for(float i = 0; i <= 2; i+=deltaT)
    {
        f_1D(u,deltaT,size);
    }


    //print tableau valeurs
    //printArray(u,size);
    

    
    double  t1 = omp_get_wtime();
    double  temps_reel=t1-t0;
    printf( " temps  reel %lf : \n", temps_reel);

    t0 = omp_get_wtime();     

    for(float i = 0; i <= 2; i+=deltaT)
    {
        f_1D_parallele(u1,deltaT,size);
    }

    //print tableau valeurs
    //printArray(u,size);

   
    t1 = omp_get_wtime ();
    temps_reel=t1-t0;
    printf( " temps  reel %lf : \n", temps_reel);


  /*
  //-------------------------------------------------------------
  // WRITE RESULT IN A PGN IMAGE 
  //-------------------------------------------------------------
   writeimg(file_out, Tdt, rw, cl, v);
   free(Tdt);
   free(T);
   */
   return(0);
}