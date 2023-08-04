#include <iostream>
using namespace std;

std::string get_middle(std::string input) 
{
    string answer;
    int point1=0;
    int point2=0;
    if(input.length()%2==0){
        for(;point1<input.length();point1+=2,point2++);
        answer+=input[point2-1];
        answer+=input[point2];
    }
    else{
        for(;point1<input.length();point1+=2,point2++);
        answer+=input[point2];
    }
        return answer;
}

int main(){
    string phase="test";
    cout<<get_middle(phase);
}