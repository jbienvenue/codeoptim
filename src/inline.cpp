#include "measure.h"

const int MAXID = 3;
using namespace std;

void __attribute__ ((noinline)) f(int i, int* x){
  (*x) += i;
}

void exp(int id, int n){
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
    case 2:{
      int x=0;
      int *p = &x;
      for(int i=0; i<n; i++){
        *p += i;
      }
      break;
    }
    default:
      printf("invalid id\n");
  }
}
int main(){
  const int n = 1000000000;
  const int repeat = 5;
  //record
  init(repeat, MAXID);
  for(int idRun = 0; idRun<=repeat; idRun++){
    for(int idCode=0; idCode<MAXID; idCode++){
      start();
      exp(idCode, n);
      stop(idCode, idRun);
    }
  }
  report();
}
