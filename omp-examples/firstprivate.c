#include <omp.h>
#include <stdio.h>

int main() {
    // Example of using the firstprivate clause
    int x = 5; // x has a value of 5 in the enclosing scope
    #pragma omp parallel firstprivate(x)
    {
    // Each thread has its own private copy of x, initialized with the value of x from the enclosing scope (5)
    x = x + 1; // Modifications to x by one thread are not visible to other threads
    printf("x = %d\n", x);
    }
    // The value of x in the enclosing scope is still 5
    printf("x = %d\n", x);
}
