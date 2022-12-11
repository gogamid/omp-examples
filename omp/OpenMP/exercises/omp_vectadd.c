#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{

// Initialize arrays 
int size=1000000;
int a[size];
int b[size];
int c[size];

// Time the parallel for-loop
double start,end;
start = omp_get_wtime();

// Fill with a & b with random numbers between 0 and 100
int i;
for(i=0; i<size; i++)
{
  a[i]=rand() % 100;
  b[i]=rand() % 100;
  c[i]=a[i]+b[i];
}

end = omp_get_wtime();

printf("Summed vectors a and b in %g seconds\n", end-start);

}
