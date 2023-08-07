#include <iostream>
#include <cmath>
using namespace std;

long int findNextSquare(long int sq) {
  double num = std::sqrt(sq);
  int num2 = num;
  if(num2 == num){
    return pow(num2+1,2);
  }
  else
  return -1;
}

int main(){
    long int sq=121;

}