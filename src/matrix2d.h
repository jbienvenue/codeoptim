#include <cstdlib>
#define ADDR(M, n, i, j) M[i*n+j]

void* calloc2d(int x, int y, int size){
  return calloc(x*y, size);
}
void free2d(double* M, int x){
  free(M);
}
