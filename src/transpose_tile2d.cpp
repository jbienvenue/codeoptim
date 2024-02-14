//compile : gcc -O0
#include "common.h"
#include "matrix2d.h"

const int MAXID = 4;

static unsigned long x=123456789, y=362436069, z=521288629;

unsigned long xorshf96(void) {          //period 2^96-1
  unsigned long t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;

  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;

  return z;
}

void exp(int id, int n, double* T, double* V){
  switch(id){
    case 0:
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          ADDR(V, n, i, j) += ADDR(T, n, j, i);
        }
      }
    case 1:{
        //traverse the list block by block
        //2n*b should be in the L3 cache
        //we take fator 2 of marge
        //4n*b == L3
        //b = L3/(4n)
        //in my case L3 = 4096ko
        //n is multiplyed by 8, because sizeof(double) == 8
        //so b = L3/(4*n*8) = L3/(32n) = L3/(n<<5)
        int blockSize = L3Space/(n<<5);

        //we want that blockSize is a power of 2 and divide n
        while(blockSize&(blockSize-1))blockSize--;//blockSize is a power of 2
        while(n%blockSize)blockSize >>= 1;//blockSize divide n

        for(int iBlock=0; iBlock<n; iBlock += blockSize){
          for(int jBlock=0; jBlock<n; jBlock += blockSize){
            for(int i=0; i<blockSize; i++){
              for(int j=0; j<blockSize; j++){
                ADDR(V, n, iBlock|i, jBlock|j) = ADDR(T, n, jBlock|j, iBlock|i);
              }
            }
          }
        }
      }
      break;
    case 2:{
        //traverse the list block by block
        int blockSize = L3Space/(n<<5);

        //we want that blockSize divide n
        while(n%blockSize)blockSize--;//blokSize divide n
        for(int iBlock=0; iBlock<n; iBlock += blockSize){
          for(int jBlock=0; jBlock<n; jBlock += blockSize){
            for(int i=0; i<blockSize; i++){
              for(int j=0; j<blockSize; j++){
                ADDR(V, n, iBlock|i, jBlock|j) = ADDR(T, n, jBlock|j, iBlock|i);
              }
            }
          }
        }
      }
      break;
    case 3:{
        int blockSize = L3Space/(n<<5);

        //we want that blockSize is a power of 2 and divide n
        while(blockSize&(blockSize-1))blockSize--;//blockSize is a power of 2
        while(n%blockSize)blockSize >>= 1;//blockSize divide n

        for(int iBlock=0; iBlock<n; iBlock += blockSize){
          for(int jBlock=0; jBlock<n; jBlock += blockSize){
            for(int i=0; i<blockSize; i++){
              for(int j=0; j<blockSize; j++){
                ADDR(V, n, jBlock|j, iBlock|i) = ADDR(T, n, iBlock|i, jBlock|j);
              }
            }
          }
        }
      }
      break;
    default:
      printf("invalid id\n");
  }
}
void full(double* M, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      ADDR(M, n, i, j) = xorshf96()%256;
    }
  }
}
int main(int argc, char* argv[]){
  init(argc, argv);
  const int n = 4000;
  const int repeat = 10;
  //alloc
  double* T = (double*)calloc2d(n, n, sizeof(double));
  double* V = (double*)calloc2d(n, n, sizeof(double));
  full(T, n);
  //record
  int blockSize = L3Space/(n<<5);
  while(blockSize&(blockSize-1))blockSize >>= 1;
  while(n%blockSize)blockSize >>= 1;

  int blockSize2 = L3Space/(n<<5);
  while(n%blockSize2)blockSize2--;
  printf("Block Size = %d %d\n", blockSize, blockSize2);
  init_tm(repeat, MAXID);
  for(int idRun = 0; idRun<=repeat; idRun++){
    for(int idCode=MAXID-1; idCode>=0; idCode--){
      start();
      exp(idCode, n, T, V);
      stop(idCode, idRun);
    }
  }
  free2d(T, n);
  free2d(V, n);
  report();
}
