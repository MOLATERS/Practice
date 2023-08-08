#include <iostream>
using namespace std;

std::string add_binary(uint64_t a, uint64_t b){
    uint64_t sum = a + b;
    if (sum) {
        std::string result;
        while (sum) {
            result.push_back((sum % 2) + '0');
            sum=sum/2;
        }    int i=0;
    int length=result.length();
    std::string answer(length,0);
    for(int i=0;i<length;i++){
        answer[i]=result[length-i-1];
    }
        return answer;
    }   
}

int main(){
    cout<<add_binary(4,4);
}
