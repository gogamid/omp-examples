# OpenMP

Shared memory parallel programming is a type of parallel programming in which multiple threads or processes share the same memory space, allowing them to communicate and collaborate with each other by reading and writing to the same memory locations. This type of parallel programming is typically used for applications that require high levels of communication and coordination among the different threads or processes. Example: OpenMP

The other main type of parallel programming is distributed memory parallel programming, in which each thread or process has its own memory space and communicates with the other threads or processes by sending messages over a network. In this type of parallel programming, the different threads or processes do not have direct access to each other's memory, so they must communicate through explicit message passing. This type of parallel programming is often used for applications that can be easily divided into independent tasks that can be run on separate processors or computing devices. Example: MPI

OpenMP and pthreads are both programming models that can be used for parallel programming, but there are some key differences between the two. One advantage of OpenMP is that it is more portable than pthreads, meaning that programs written using OpenMP can be more easily adapted to run on different types of hardware. Additionally, OpenMP provides a higher-level interface than pthreads, which means that programs written using OpenMP can be easier to read and understand. This can make it easier for programmers to write and maintain parallel programs using OpenMP.

The execution model of OpenMP is based on the fork-join model, in which a program is executed by a team of threads that work together to complete the work. In this model, the program starts with a single thread, known as the master thread, and then creates additional threads (known as worker threads) as needed to execute the work in parallel.
When a parallel region is encountered in the code, the master thread creates a team of threads (including itself) to execute the region in parallel. The number of threads in the team is determined by the num_threads clause of the parallel directive, or by the OpenMP runtime if this clause is not specified.
Each thread in the team then begins executing the code within the parallel region in parallel with the other threads. When a thread encounters a synchronization construct, such as a critical section or an atomic operation, it must wait for other threads to finish executing that construct before it can continue.
When all of the threads in the team have completed execution of the parallel region, the master thread joins with the other threads and the team is disbanded. The master thread then continues executing the remainder of the program sequentially.

## execution model
The execution model of OpenMP is based on the fork-join model, in which a program is executed by a team of threads that work together to complete the work. In this model, the program starts with a single thread, known as the master thread, and then creates additional threads (known as worker threads) as needed to execute the work in parallel.

When a parallel region is encountered in the code, the master thread creates a team of threads (including itself) to execute the region in parallel. The number of threads in the team is determined by the num_threads clause of the parallel directive, or by the OpenMP runtime if this clause is not specified.

Each thread in the team then begins executing the code within the parallel region in parallel with the other threads. When a thread encounters a synchronization construct, such as a critical section or an atomic operation, it must wait for other threads to finish executing that construct before it can continue.

When all of the threads in the team have completed execution of the parallel region, the master thread joins with the other threads and the team is disbanded. The master thread then continues executing the remainder of the program sequentially.

# synchronization
To use synchronization in OpenMP, you can use one of the built-in synchronization mechanisms provided by the OpenMP library. These mechanisms include critical sections, atomic operations, and ordered regions.

A critical section is a block of code that is executed by only one thread at a time. To create a critical section, you can use the #pragma omp critical directive before the block of code that you want to execute exclusively. 
```c
#pragma omp critical
{
  // This block of code will be executed by only one thread at a time.
  // Any other threads that try to enter this block will be blocked
  // until the current thread has finished executing the code.
}
```
An atomic operation is a low-level synchronization mechanism that allows you to perform a single, indivisible operation on a shared variable. To use an atomic operation, you can use the #pragma omp atomic directive before the operation that you want to execute atomically. For example:
```c
#pragma omp atomic
shared_variable += 1;
```
An ordered region is a block of code that is executed in a specific order by the threads in a team. To create an ordered region, you can use the #pragma omp ordered directive before the block of code that you want to execute in order. For example:
```c
#pragma omp ordered
{
  // This block of code will be executed in order by the threads in the team.
  // The first thread to enter the ordered region will execute the code first,
  // followed by the second thread, and so on.
}
```
