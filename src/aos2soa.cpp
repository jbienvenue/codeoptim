#include "measure.h"
const int MAXID = 2;

typedef struct{
  int x;
  int y;
  int z;
}point;

void exp(int idCode, int n, point* ps, int* psx, int* psy, int* psz){
  switch(idCode){
    case 0:
      for(int i=0; i<n; i++){
        ps[i].x++;
      }
      break;
    case 1:
      for(int i=0; i<n; i++){
        psx[i]++;
      }
      break;
    default:
      printf("invalid id\n");
  }
}

int main(){
  const int n = 10000000;
  const int repeat = 100;
  //alloc
  point* ps = (point*)calloc(n, sizeof(point));
  int* psx = (int*)calloc(n, sizeof(int));
  int* psy = (int*)calloc(n, sizeof(int));
  int* psz = (int*)calloc(n, sizeof(int));
  //record
  init(repeat, MAXID);
  for(int idRun = 0; idRun<=repeat; idRun++){
    for(int idCode=0; idCode<MAXID; idCode++){
      start();
      exp(idCode, n, ps, psx, psy, psz);
      stop(idCode, idRun);
    }
  }
  report();
}
