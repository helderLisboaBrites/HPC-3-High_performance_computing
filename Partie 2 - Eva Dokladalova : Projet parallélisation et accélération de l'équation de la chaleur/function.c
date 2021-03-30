/*******************************************************************/ 
/*  INF-4101C - Travaux pratiques 2
 *  Lecture / écriture d'une matrice 2D pour des tests
 *  des techniques HPC, on utilise le moyen d'une image pour visualiser le résultat
 *  Eva Dokladalova,  2019
 */

#include "function.h"
#include "omp.h"
//------------------------------------------------------------------
// ONLY FOR PGN IMAGES type P2 !!!
//------------------------------------------------------------------
//open image file and access data, allocate an image with file data; 
float * readimg(char *filename, int *rs, int *cs, int *vs)
{
  float *im; // input data
  char *rd;
  int c,v;
  int rw; //row size
  int cl; //column size
  char buffer[BSIZE];
  FILE *fd = NULL;
  
  // open input file 
  fd = fopen(filename,"r");
  if (fd==NULL)
    {
      fprintf(stderr, "Input image reading failed)\n");
      return (0);
    }
 
  // verify file type BLACK ADN WHITE ASCII PGN = P2
  rd = fgets(buffer, BSIZE, fd);
  if (!rd)
    {
      fprintf(stderr, "Reading failed (%s)\n", filename);
      return 0;
    }
  if ((buffer[0] != 'P') || (buffer[1]!= '2'))
    {   fprintf(stderr,"%s : invalid image format\n", filename);
      
      return (0);
    }
  do
    { // comment in pgn file ?
      rd = fgets(buffer, BSIZE, fd); /* commentaire #*/
      if (!rd)
	{
	  fprintf(stderr, "%s: fgets returned without reading\n", filename);
	  return 0;
	}
      
    } while (!isdigit(buffer[0]));
  
  // scan image size rw = number of rows; cl = number of columns
  c = sscanf(buffer, "%d %d", &rw, &cl);
  rd = fgets(buffer, BSIZE, fd);
  // scan maximal pixel value, should be == 255
  c = sscanf(buffer, "%d", &v);
  //data allocation and initialization
  im = (float *) calloc (rw*cl,sizeof(float));
  if (im==NULL)
    {
      fprintf(stderr, "Data allocation (failed %d) bytes)\n", rw*cl);
      return (0);
    }
  int i;
  // data initialization
  int N = rw*cl*sizeof(uint8);
  for (i=0;i<N;i++)
    {
      fscanf(fd, "%d", &c);
      im[i]=(float) c;
    }
  // close file and return pointer to the iamge data
  fclose(fd);  
  *cs = cl;
  *rs = rw;
  *vs = v;
  return(im);
}

//------------------------------------------------------------------
// ONLY FOR PGN IMAGES type P2 !!!
//------------------------------------------------------------------
// write image in a file
//----------------------------------------------------------------
void writeimg(char *filename, float *im, int rs, int cs, int vs)
{
  int cl;
  int rw;
  int v;
  int N;
  FILE *fd_out;
  int i;
  
  cl = cs;
  rw = rs;
  v = vs;
  N = cl*rw;
 
  fd_out = fopen(filename,"w");
  if (!fd_out)
    {
      fprintf(stderr, "%s: cannot open file\n", filename);
      exit(0);
    } 
  fputs("P2\n", fd_out);
  fprintf(fd_out, "# comment\n");
  fprintf(fd_out, "%d %d\n", rw,cl);
  fprintf(fd_out, "%d\n", v);
  for (i = 0; i < N; i++)
    { 
      fprintf(fd_out, "%d \n", (int) (im[i]+0.5));
    }      
  fclose(fd_out);
}


void f_1D(float * u,float deltaT, int size)
{
    float* u_tmp = (float*) calloc(size, sizeof(float));

    u_tmp[0] = u[0];
    u_tmp[size] = u[size];
    //calcul 
    for(int x = 1; x<size-1; x++ )
    {
        u_tmp[x] = u[x]+ deltaT*(u[x+1]-2*u[x]+u[x-1])/2;
 
    }

    //copie tableau
    for(int x = 0; x<size; x++ )
    {
        u[x]=u_tmp[x];
    }

    free(u_tmp);
}

void f_1D_parallele(float * u,float deltaT, int size)
{
    float* u_tmp = (float*) calloc(size, sizeof(float));

    u_tmp[0] = u[0];
    u_tmp[size] = u[size];
    //calcul 
    omp_set_num_threads(4);
    #pragma omp parallel for 
    for(int x = 1; x<size-1; x++ )
    {
        u_tmp[x] = u[x]+ deltaT*(u[x+1]-2*u[x]+u[x-1])/2;
    }
    
    //copie tableau
    #pragma omp parallel for
    for(int x = 0; x<size; x++ )
    {
        u[x]=u_tmp[x];
        //memcpy
    }

    free(u_tmp);
}




void f_2D(float ** u, float  deltaT,int Xsize,int Ysize )
{
  float** u_tmp = (float**) calloc(Xsize, sizeof(float*));
  for(int i = 0; i<Xsize; i++) u_tmp[i] = calloc(Ysize, sizeof(float));
/*
  //calcul 
  for(int x = 0; x<Xsize-1; x++ )
  {
    for(int y = 0; y<Ysize-1; y++ )
    {
      if(x == 0 && y == 0)
      {
        u_tmp[x][y] = 0;
      }
      else if(x == 0)
      {
        u_tmp[x][y] = u[x][y]+ deltaT*((u[x+1][y]- 2*u[x][y] + u[x][y])/2 + (u[x][y+1]-2*u[x][y]+u[x][y-1]))/2;
      }
      else if(y==0)
      {
        u_tmp[x][y] = u[x][y]+ deltaT*((u[x+1][y]- 2*u[x][y] + u[x-1][y])/2 + (u[x][y+1]-2*u[x][y]+u[x][y]))/2;
      }
      else
      {
        u_tmp[x][y] = u[x][y]+ deltaT*((u[x+1][y]- 2*u[x][y] + u[x-1][y])/2 + (u[x][y+1]-2*u[x][y]+u[x][y-1]))/2;
      }
    }
  }
*/
  //pixel non bord
  for(int x = 1; x<Xsize-1; x++)
    for(int y =1; y<Ysize-1; y++)
        u_tmp[x][y] = u[x][y]+ deltaT*(u[x+1][y] + u[x-1][y]+u[x][y+1]+u[x][y-1] - 4*u[x][y]) / 4;
  //pixels bord en gauche
  for(int x = 1; x<Xsize-1; x++)
        u_tmp[x][0] = u[x][0]+ deltaT*(u[x+1][0] + u[x-1][0]+u[x][0]+u[x][0] - 4*u[x][0]) / 4;
  //pixels bord en droit
  for(int x = 1; x<Xsize-1; x++)
        u_tmp[x][Ysize-1] = u[x][Ysize-1]+ deltaT*(u[x+1][Ysize-1] + u[x-1][Ysize-1]+u[x][Ysize-1]+u[x][Ysize-1] - 4*u[x][Ysize-1]) / 4;

  //pixels bord en haut
  for(int y =1; y<Ysize-1; y++)
        u_tmp[0][y] = u[0][y]+ deltaT*(u[0][y] + u[0][y]+u[0][y+1]+u[0][y-1] - 4*u[0][y]) / 4;
  //pixels bord en bas
  for(int y =1; y<Ysize-1; y++)
        u_tmp[Xsize-1][y] = u[Xsize-1][y]+ deltaT*(u[Xsize-1][y] + u[Xsize-1][y]+u[Xsize-1][y+1]+u[Xsize-1][y-1] - 4*u[Xsize-1][y]) / 4;

  //les 4 coins
  u_tmp[0][0] = 0;
  u_tmp[Xsize-1][Ysize-1] = 0;
  u_tmp[Xsize-1][0] = 0;
  u_tmp[0][Ysize-1] = 0;



  //copie tableau
  for(int x = 0; x<Xsize; x++ )
  {
      for(int y = 0; y<Ysize; y++ )
  {
      u[x][y]=u_tmp[x][y];
  }

  }

  for (int i = 0; i < Xsize; i++){  
   free(u_tmp[i]);  
  }  
  free(u_tmp);  
}



float* readFromData(char *filename, int rs){
    FILE *fd = NULL;

    // open input file 
    fd = fopen(filename,"r");
    if (fd==NULL)
    {
        fprintf(stderr, "Input image reading failed)\n");
        return (0);
    }

    float* im = (float *) calloc (rs,sizeof(float));
    if (im==NULL)
    {
        fprintf(stderr, "Data allocation (failed %d) bytes)\n", rs);
        return (0);
    }

    // data initialization
    int N = rs*sizeof(float);
    float c;
    for (int i=0; i<rs;i++)
    {
        fscanf(fd, "%f", &c);
        im[i]=(float) c;
    }
    return (im);
}



void print_1D_Array(float* u, int size){
        //print tableau valeurs
    for(int i =0; i<size; i++){
        printf(" %.3f ", u[i]);
    }
    printf(" \n ");
}

void print_2D_Array(float** u, int Xsize,int Ysize){
        //print tableau valeurs
    for(int i =0; i<Xsize; i++){
      for(int j = 0; j<Ysize; j++)
        printf(" %.3f ", u[i][j]);
       printf(" \n ");
    }
    printf(" \n ");
}