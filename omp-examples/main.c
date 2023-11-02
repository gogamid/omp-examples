#include <stdio.h>
#include <omp.h>

int main()
{
  // Set the number of threads to use for the parallel for loop
  omp_set_num_threads(4);

  // Define the for loop that will be executed in parallel
  #pragma omp parallel for
  for (int i = 0; i < 100; i++)
  {
    // Each thread will print its own thread ID and the value of i
    printf("Thread %d: i = %d\n", omp_get_thread_num(), i);
  }

  return 0;
}
