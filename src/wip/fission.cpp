#include "measure.h"

const int MAXID = 2;
using namespace std;
const int L3Space = 4194304;

void exp(int id, int n, double* T, double* U){
  switch(id){
    case 0:
      //a loop with two operation in the body
      for(int r=0; r<10; r++){
        for(int i=0; i<n; i++){
          T[i]++;
          U[i]++;
        }
      }
      break;
    case 1:
      //with loop fission
      for(int r=0; r<10; r++){
        for(int i=0; i<n; i++){
          T[i]++;
        }
      }
      for(int r=0; r<10; r++){
        for(int i=0; i<n; i++){
          U[i]++;
        }
      }
      break;
    default:
      printf("invalid id\n");
  }
}
int main(){
  const int n = L3Space*3/(4*sizeof(double));
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
