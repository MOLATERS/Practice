#include <iostream>
using namespace std;

int MaxMultiple(int divisor,int bound){
    if(bound<0)return 1;
    int save = bound%divisor;
    return bound-save;
}