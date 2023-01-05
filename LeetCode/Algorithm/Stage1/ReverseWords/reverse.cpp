#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int head;
        int tail;
        int place=0;
        while(place<s.size()){
            head=place;
            while(s[place]!=' '&&place<s.size())place++;
            tail=place-1;
            while(head<tail){
                swap(s[head],s[tail]);
                head++;
                tail--;
            }
            place++;
        }
        return s;
    }
    void swap(char &a,char &b){
        char temp;
        temp=a;
        a=b;
        b=temp;
    }
};
main(){
    string s="hello my son!";
    Solution q;
    string answer;
    answer=q.reverseWords(s);
    cout<<answer;
} 