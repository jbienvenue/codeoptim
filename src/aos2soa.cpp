#include "common.h"
const int MAXID = 2;

typedef struct{
  int x;
  int y;
  int z;
}point;

void exp(int idCode, int n, point* ps, int* psx, int* psy, int* psz){
  switch(idCode){
    case 0:
      //modify data in struct wich is in a list : load all struct to modify only one part
      for(int i=0; i<n; i++){
        ps[i].x++;
      }
      break;
    case 1:
      // modify data in list : load only the list where we modify one element
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
  init_tm(repeat, MAXID);
  for(int idRun = 0; idRun<=repeat; idRun++){
    for(int idCode=0; idCode<MAXID; idCode++){
      start();
      exp(idCode, n, ps, psx, psy, psz);
      stop(idCode, idRun);
    }
  }
  report();
}
