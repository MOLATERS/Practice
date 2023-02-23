#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream answer("answer.txt");
    ofstream myanswer("myanswer,txt");
    string temp1;
    string temp2;
    do{
        getline(answer,temp2);
        getline(answer,temp1);
    }
}