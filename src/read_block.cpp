//compile : gcc -O0
#include "measure.h"

const int MAXID = 2;
using namespace std;


void exp(int id, int n, double* T){
  switch(id){
    case 0:
      //traverse a list
      for(int i=0; i<n; i++){
        T[i]++;
      }
      break;
    case 1:{
        //traverse the list block by block
        int b=8;
        int b2=1<<b;
        for(int bi=0; bi<n; bi+=b2){
          for(int i=0; i<b2; i++){
            T[bi|i]++;
          }
        }
      }
      break;
    default:
      printf("invalid id\n");
  }
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
}
