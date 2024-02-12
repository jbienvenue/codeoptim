#include "measure.h"

const int MAXID = 3;
using namespace std;


void exp(int id, int n, double* T, double* U){
  switch(id){
    case 0:
      //a loop with two operation in the body
      for(int i=0; i<n; i++){
        T[i]++;
        U[i]++;
      }
      break;
    case 1:
      //with loop fission
      for(int i=0; i<n; i++){
        T[i]++;
      }
      for(int i=0; i<n; i++){
        U[i]++;
      }
      break;
    case 2:
      // traversal in reverse order
      for(int i=n; i>=0; i--){
        T[i]++;
      }
      for(int i=n; i>=0; i--){
        U[i]++;
      }
      break;
    default:
      printf("invalid id\n");
  }
}
int main(){
  const int n = 100000000;
  const int repeat = 2;
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
