#include "measure.h"

const int MAXID = 2;

void exp(int idCode, int n, int** T){
  switch(idCode){
    case 0:
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          T[j][i]++;
        }
      }
      break;
    case 1:
      for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
          T[j][i]++;
        }
      }
      break;
    default:
      printf("invalid id\n");
  }
}

int main(){
  const int n = 1000;
  const int repeat = 1000;
  //alloc
  int** T = (int**)calloc(n, sizeof(int*));
  for(int i = 0; i < n; i++)
      T[i] = (int*)calloc(n, sizeof(int));
  //record
  init(repeat, MAXID);
  for(int idRun = 0; idRun<=repeat; idRun++){
    for(int idCode=0; idCode<MAXID; idCode++){
      start();
      exp(idCode, n, T);
      stop(idCode, idRun);
    }
  }
  report();
  for(int i=0; i<n; i++)
    free(T[i]);
}