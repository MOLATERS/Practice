#include <queue>
#include <iostream>
using namespace std;

bool narcissistic( int value ){
    int length =0;
    int origin= value;
    int sum=0;
    int temp=1;
    queue<int> digits;
    while(value){
        digits.push(value%10);
        // cout<<digits.front()<<endl;
        value/=10;
    }
    // for(int i=0;i<digits.size();i++){
    //     cout<<digits.front()<<endl;
    //     digits.pop();
    // }
    int size = digits.size();
    while(!digits.empty()){
        int number = digits.front();
        for(int i=0;i<size;i++){
            temp*= number;
        }
        digits.pop();
        sum+=temp;
        temp=1;
    }
    return sum==origin;
 }

 int main(){
    if(narcissistic(153)){
        cout<<"true";
    }
 }