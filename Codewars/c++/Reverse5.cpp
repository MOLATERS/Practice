#include <iostream>
#include <vector>
using namespace std;
string split(string str, char delimiter);
std::string reverse(std::string &str);
std::string spinWords(const std::string &str) {
    return split(str,' ');
}
string split(string str, char delimiter) {
    char temp;
    string word;
    string result;
    for(int i=0;i<str.length();i++){
        temp = str[i];
        if(temp!=delimiter)
            word.push_back(temp);
        if(temp == delimiter||i == str.length()-1){
            word = reverse(word);
            if(i==str.length()-1){
                result.append(word);
                continue;
            }
            result.append(word+" ");
            word ="";
        }
    }
    return result;
}

std::string reverse(std::string &str) {
    int length = str.length();
    if(length>=5){
        int i=0;
        int j=length-1;
        for(;i<j;i++,j--){
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
        return str;
    }
    else{
        return str;
    }
}

int main(){
    string phrase = "Hey fellow warriors";
    string phrase2 = "This is a test";
    string phrase3 = "This is another test";
    string wordlist = spinWords(phrase3);
    cout<<wordlist;
}