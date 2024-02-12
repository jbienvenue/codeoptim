#include "measure.h"
const int MAXID = 2;

void exp(int idCode, int n, int* T, int* U){
  switch(idCode){
    case 0:
      for(int j=0; j<100; j++){
        for(int i=0; i<n; i++){
          if(j<50)
            T[i] += 1;
          else
            U[i] += 2;
        }
      }
      break;
    case 1:
      for(int j=0; j<100; j++){
        if(j<50){
          for(int i=0; i<n; i++){
            T[i] += 1;
          }
        }else{
          for(int i=0; i<n; i++){
            U[i] += 2;
          }
        }
      }
      break;
    default:
      printf("invalid id\n");
  }
}

int main(){
  const int n = 10000000;
  const int repeat = 2;
  //alloc
  int* T = (int*)calloc(n, sizeof(int));
  int* U = (int*)calloc(n, sizeof(int));
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
