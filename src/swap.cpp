#include "common.h"

const int MAXID = 2;

void exp(int idCode, int n, int** T){
  switch(idCode){
    case 0:
      //modify element by element in different list : load full list for modify only one element and pass to the next list
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          T[j][i]++;
        }
      }
      break;
    case 1:
      //modify element by element in same list, list by list : load full list to modify all list and pass to the next
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

int main(int argc, char* argv[]){
  int _ = 1000;
  const int n = init(argc, argv, _);
  const int repeat = 1000;
  //alloc
  int** T = (int**)calloc(n, sizeof(int*));
  for(int i = 0; i < n; i++)
      T[i] = (int*)calloc(n, sizeof(int));
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
  for(int i=0; i<n; i++)
    free(T[i]);
}
