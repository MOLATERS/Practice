#include <iostream>
#include <vector>
using namespace std;

std::vector<std::string> wave(std::string y){
  std::vector<std::string> result;
  int length = y.length();
  for(int i = 0; i < length; i++){
    std::string temp = y;
    if(temp[i] == ' '){
        continue;
    }
    temp[i]-=32;
    result.push_back(temp);
  }
  return result; 
}


int main(){
    vector<string> result;
    result = wave("hello");
    for(auto x : result){
        cout<<x<<endl;
    }
	int temp = 0;
	return temp;
}
