#pragma omp parallel shared(w, sum) private(x, i) 
// #pragma omp for reduction(+:sum)