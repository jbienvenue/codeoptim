#include "measure.h"
const int MAXID = 2;

typedef struct{
  int data[32];
}point;

void exp(int idCode, int n, point* ps, int** pss){
  switch(idCode){
    case 0:
      for(int i=0; i<n; i++){
        ps[i].data[0]++;
      }
      break;
    case 1:
      for(int i=0; i<n; i++){
        pss[0][i]++;
      }
      break;
    default:
      printf("invalid id\n");
  }
}

int main(){
  const int n = 10000000;
  const int repeat = 10;
  //alloc
  point* ps = (point*)calloc(n, sizeof(point));
  int** pss = (int**)calloc(32, sizeof(int*));
  for(int i=0; i<32; i++){
    pss[i] = (int*)calloc(n, sizeof(int));
  }
  //record
  init(repeat, MAXID);
  for(int idRun = 0; idRun<=repeat; idRun++){
    for(int idCode=0; idCode<MAXID; idCode++){
      start();
      exp(idCode, n, ps, pss);
      stop(idCode, idRun);
    }
  }
  report();
}
