#include "common.h"

const int MAXID = 3;

void __attribute__ ((noinline)) f(int i, int* x){
  (*x) += i;
}

int total = 0;

void exp(int id, int n){
  switch(id){
    case 0:{
      //a loop with two operation in the body
        int x=0;
        for(int i=0; i<n; i++){
          f(i, &x);
        }
        total += x;
      }
      break;
    case 1:{
      //with loop fission
        int x=0;
        for(int i=0; i<n; i++){
          x += i;
        }
        total += x;
      }
      break;
    case 2:{
      int x=0;
      int *p = &x;
      for(int i=0; i<n; i++){
        *p += i;
      }
      total += x;
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
  init_tm(repeat, MAXID);
  for(int idRun = 0; idRun<=repeat; idRun++){
    for(int idCode=0; idCode<MAXID; idCode++){
      start();
      exp(idCode, n);
      stop(idCode, idRun);
    }
  }
  report();
  printf("\tresult :%d\n", total);
}
