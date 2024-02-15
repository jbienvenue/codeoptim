#include "common.h"

const int MAXID = 2;

void exp(int id, int n, double* T){
  switch(id){
    case 0:
      //change element all 64 element
      for(int j=0; j<1000; j++){
        for(int i=0; i<n; i+=64){
          T[i]++;
        }
      }
      break;
    case 1:{
        //load the element do we want to change in second list,
        //modify element in second,
        //reload second in the first list
        int n64 = n/64;
        double* U = (double*)calloc(n64, sizeof(double));
        for(int i=0; i<n64; i++){
          U[i] = T[i<<6];
        }
        for(int j=0; j<1000; j++){
          for(int i=0; i<n64; i++){
            U[i]++;
          }
        }
        for(int i=0; i<n64; i++){
          T[i<<6] = U[i];
        }
        free(U);
      }
      break;
    default:
      printf("invalid id\n");
  }
}

int main(int argc, char* argv[]){
  int _ = 100000000;
  const int n = init(argc, argv, _);
  const int repeat = 3;
  //alloc
  double* T = (double*)calloc(n, sizeof(double));
  //record
  init_tm(repeat, MAXID);
  for(int idRun = 0; idRun<=repeat; idRun++){
    for(int idCode=0; idCode<MAXID; idCode++){
      start();
      exp(idCode, n, T);
      stop(idCode, idRun);
    }
  }
  report();
}
