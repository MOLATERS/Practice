#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int head=0;
        int tail=s.size()-1;
        while(head<tail){
            swap(s[head],s[tail]);
            head++;
            tail--;
        }
    }
};

int main(){
    vector<char> s;
    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
}