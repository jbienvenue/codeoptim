#include "measure.h"

const int MAXID = 2;
using namespace std;

void f(int i, int* x){
  (*x) += i;
}

void exp(int id, int n, double* T, double* U){
  switch(id){
    case 0:{
      //a loop with two operation in the body
        int x=0;
        for(int i=0; i<n; i++){
          f(i, &x);
        }
      }
      break;
    case 1:{
      //with loop fission
        int x=0;
        for(int i=0; i<n; i++){
          x += i;
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
  double* U = (double*)calloc(n, sizeof(double));
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
