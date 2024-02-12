#include <chrono>
#include <cstdio>
#include <cstdlib>
typedef std::chrono::steady_clock::time_point mesure;

mesure start(){
    return std::chrono::steady_clock::now();
}
int stop(mesure tm_start){
    mesure tm_end = std::chrono::steady_clock::now();
    int micro = std::chrono::duration_cast<std::chrono::microseconds>(tm_end-tm_start).count();
    return micro/1000;
}