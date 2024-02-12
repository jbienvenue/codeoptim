#include "measure.h"

const int MAXID = 3;
using namespace std;

void exp(int id, int n, double* T, double* U){
    switch(id){
        case 0:
            for(int i=0; i<n; i++){
                T[i]++;
                U[i]++;
            }
            break;
        case 1:
            for(int i=0; i<n; i++){
                T[i]++;
            }
            for(int i=0; i<n; i++){
                U[i]++;
            }
            break;
        case 2:
            for(int i=n; i; i--){
                T[i]++;
            }
            for(int i=n; i; i--){
                U[i]++;
            }
            break;
    }
}
int main(){
    const int n=1000000;
    const int repeat=50;
    //alloc
    double* T = (double*)calloc(n, sizeof(double));
    double* U = (double*)calloc(n, sizeof(double));
    //record
    for(int id=0; id<MAXID; id++){
        mesure tm_start = start();
        for(int k = 0; k<repeat; k++){
            exp(id, n, T, U);
        }
        printf("%d\n", stop(tm_start));
    }
}