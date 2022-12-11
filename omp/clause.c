#include <omp.h>
#include <stdio.h>

int main() {
  // Example of using the firstprivate clause
  int x = 5;  // x has a value of 5 in the enclosing scope
#pragma omp parallel firstprivate(x)
  {
    // Each thread has its own private copy of x, initialized with the value of
    // x from the enclosing scope (5)
    x = x + 1;  // Modifications to x by one thread are not visible to other threads
    printf("x = %d\n", x);
  }
  // The value of x in the enclosing scope is still 5
  printf("x = %d\n", x);

  // // Example of using the lastprivate clause
  // int y = 0; // y has a value of 0 in the enclosing scope
  // #pragma omp parallel
  // {
  //   int x = 0; // x is private to each thread within the parallel region
  //   #pragma omp for lastprivate(x)
  //   for (int i = 0; i < 100; i++) {
  //     x = x + 1; // Each thread increments its own private copy of x
  //   }
  //   // After the loop has completed, the value of x from the last iteration
  //   of the loop is assigned to y in the enclosing scope
  //   // (the value of x will be 100 for each thread)
  // }
  // // The value of y in the enclosing scope is 100

  // // Example of using the threadprivate clause
  // int x = 5; // x has a value of 5 in the enclosing scope
  // #pragma omp parallel threadprivate(x)
  // {
  //   // Each thread has its own private copy of x, initialized with the value
  //   of x from the enclosing scope (5) x = x + 1; // Modifications to x by one
  //   thread are not visible to other threads
  // }
  // // The value of x in the enclosing scope is still 5

  // // Example of using the copyin clause
  // int x = 5; // x has a value of 5 in the enclosing scope
  // #pragma omp parallel copyin(x)
  // {
  //   // Each thread has its own private copy of x, initialized with the value
  //   of x from the enclosing scope (5)
  //   // Modifications to x by one thread are not visible to other threads
  // }
  // // The value of x in the enclosing scope is still 5

  // // Example of using the reduction clause
  // int x = 0; // x has a value of 0 in the enclosing scope
  // #pragma omp parallel for reduction(+:x)
  // for (int i = 0; i < 100; i++) {
  //   x = x + i; // Each thread increments its own private copy of x with the
  //   value of i
  // }
  // After the loop has completed, the values of x from all threads are summed
  // using the + operator, and the result is assigned to x in the enclosing
  // scope (the value of x will be 4950 in the enclosing scope)
}