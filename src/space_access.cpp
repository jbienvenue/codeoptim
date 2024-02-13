#include "measure.h"

const int MAXID = 2;

void exp(int id, int n, double* T, double* U){
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
      }
      break;
    default:
      printf("invalid id\n");
  }
}

int main(){
  const int n = 100000000;
  const int repeat = 3;
  //alloc
  double* T = (double*)calloc(n, sizeof(double));
  double* U = (double*)calloc(n/64, sizeof(double));
  //record
  init(repeat, MAXID);
  for(int idRun = 0; idRun<=repeat; idRun++){
    for(int idCode=0; idCode<MAXID; idCode++){
      start();
      exp(idCode, n, T, U);
      stop(idCode, idRun);
    }
  }
  report();
}
