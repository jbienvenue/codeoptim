#include "measure.h"

const int MAXID = 2;
using namespace std;
int total=0;

void exp(int id, int n, double* T){
  int s=0;
  switch(id){
    case 0:{
      //a loop with two operation in the body
      for(int i=0; i<n; i++){
        T[i] = i;
      }
      for(int i=0; i<n; i++){
        s += T[i];
      }
      }
      break;
    case 1:{
        for(int i=0; i<n; i++){
          T[i] = i;
          s += T[i];
        }
        break;
      }
    default:
      printf("invalid id\n");
  }
  total += s;
}
int main(){
  const int n = 100000000;
  const int repeat = 10;
  //alloc
  double* T = (double*)calloc(n, sizeof(double));
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
  printf("\tresult: %d\n", total);
}
