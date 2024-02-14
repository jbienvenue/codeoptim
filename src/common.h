#include <chrono>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef std::chrono::steady_clock::time_point mesure;

mesure tm_start;
int* exec_time_sum;//index by measure idCode
int repeat;
int nbIDCode;

int L3Space=4194304;

void init(int argc, char* argv[]){
  if(argc>1){
    L3Space = atoi(argv[1]);
  }
}

void start(){
  tm_start=std::chrono::steady_clock::now();
}
void init_tm(int repeatArg, int nbIDCodeArg){
  nbIDCode = nbIDCodeArg;
  repeat = repeatArg;
  exec_time_sum = (int*)calloc(nbIDCode, sizeof(int));
}

void stop(int idCode, int idRun){
  if(idRun != 0){
    mesure tm_end = std::chrono::steady_clock::now();
    int micro = std::chrono::duration_cast<std::chrono::microseconds>(tm_end-tm_start).count();
    exec_time_sum[idCode] += micro;
  }
}

void report(){
  int baseline = exec_time_sum[0];
  printf("for idCode = 0 : %dms\n", baseline/1000);
  for(int idCode=1; idCode<nbIDCode; idCode++){
    int st_time = exec_time_sum[idCode];
    double r=(double)(baseline)/st_time;
    printf("for idCode = %d : %dms ", idCode, st_time/1000);
    if(r>2){
      printf("(%.1fx)\n", r);
    }else{
      printf("(%s%.0f%%)\n", ((r<1)?"+":""), (1/r-1)*100);
    }
  }
  free(exec_time_sum);
}
