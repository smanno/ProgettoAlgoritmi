#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

#include "funzioni.h"
#include "DoubleHeap.h"
#include "algoritmiSelezione.h"

int const numberTestRes = 100;

using namespace std;
using namespace std::chrono;

double getDuration(steady_clock::time_point start, steady_clock::time_point end){
    typedef duration<double, /*microseconds*/nanoseconds::period> nanosecs;
    return duration_cast<nanosecs>(end-start).count();
}

double calcoloRes(){
    steady_clock::time_point start = steady_clock::now();
    steady_clock::time_point end;
    do{ end = steady_clock::now(); } while (start==end);
    return getDuration(start,end);
}

double resolution(int n){
    vector<double> sampleRes;
    for(int i=0;i<n;i++){
        sampleRes.push_back(calcoloRes());
    }
    sort(sampleRes.begin(),sampleRes.end());
    //cout<<sampleRes;
    if(n % 2 == 0)
        return (sampleRes[n/2 - 1] + sampleRes[n/2])/2;
    return sampleRes[n/2];
}

int main() {
    double control = 0.1;
    double res = resolution(numberTestRes);
    cout<<control+res; // without it output is 1000 instead of 100 ???

    vector<int> vettoreProva = {9,2,3,99,1,0};
    //quickSelect(vettoreProva,4);
    heapSelect(vettoreProva,1);
    cout<<vettoreProva;

    return 0;
}
