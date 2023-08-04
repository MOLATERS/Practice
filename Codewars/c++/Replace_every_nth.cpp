#include <iostream>
#include <vector>
using namespace std;

class Kata
{
public:
    std::string replaceNth(std::string text, int n, char oldValue, char newValue)
    {
        if(n<=0) return text;
        // std::vector<int> accur = new std::vector<int>(text.length());
        int* accur = new int[text.length()];
        int tag = Tag(accur,text,oldValue);
        for(int i=n-1;i<tag;i+=n){
            text[accur[i]]=newValue;
        }
        return text;
    }
    int Tag(int* accur,std::string text,char oldValue){
        int tag=0;
        for(int i=0;i<text.length();i++){
            if(text[i]==oldValue){
                accur[tag]=i;
                tag++;
            }
        }
        return tag;
    }
};

int main(){
    string text = "Vader said: No, I am your father!";
    Kata k;
    cout<<k.replaceNth(text,0,'a','o');
}