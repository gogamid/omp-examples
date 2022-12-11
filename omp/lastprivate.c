#include <omp.h>
#include <stdio.h>

int main() {
    // Example of using the lastprivate clause
    int y = 0; // y has a value of 0 in the enclosing scope
     int x = 0; // x is private to each thread within the parallel region
    #pragma omp parallel
    {
    #pragma omp for firstprivate(x)
    for (int i = 0; i < 100; i++) {
        x = x + 1; // Each thread increments its own private copy of x
    }
    // After the loop has completed, the value of x from the last iteration of the loop is assigned to y in the enclosing scope
// (the value of x will be 100 for each thread)
    }
     y = x;
    // The value of y in the enclosing scope is 100
    printf("The value of y is %d\n", y); // Prints "The value of y is 100"
}
