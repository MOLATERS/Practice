#include <iostream>
#define INFINIT 50000 
using namespace std;

int solution(int number) 
{
  int sum=0;
  if(number<=0)return 0;
  else{
       int i=0,j=0,k=0;
      while(1){
        if(k==INFINIT&&j!=INFINIT&&i!=INFINIT){
            sum += i+j;
        }
        else if(j==INFINIT&&i!=INFINIT){
            sum += i;
        }
        else if(k==INFINIT&&j==INFINIT&&i==INFINIT)break;
        else{
            sum+=i+j-k;
        }
        if(k+15<number)k+=15;
        else k=INFINIT;
        if(j+5<number)j+=5;
        else j=INFINIT;
        if(i+3<number)i+=3;
        else i=INFINIT;
      }
  }
  return sum;
}

int main(){
    cout<<solution(10);
}
