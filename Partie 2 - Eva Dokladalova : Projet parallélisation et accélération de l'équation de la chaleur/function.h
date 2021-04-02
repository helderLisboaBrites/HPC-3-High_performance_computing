/*******************************************************************/

#ifndef FUNCTION_H_ 
#define FUNCTION_H_

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>

// types definitions
typedef unsigned char uint8;

// buffer size for input image reading
#define BSIZE 1000

// function declarations
float * readimg(char *, int *, int *, int *);
void writeimg(char *, float *, int , int, int);

float * readFromData(char *, int );
void print_1D_Array(float* , int );
void f_1D(float *, float ,int  );

void f_1D_parallel(float *, float ,int  );
void f_1D_parallel_static(float *, float ,int  );
void f_1D_deroulage(float *, float ,int  );
void f_1D_deroulage_parallel(float *, float ,int  );

void f_2D(float **, float ,int,int  );

void print_2D_Array(float** , int ,int);

#endif


