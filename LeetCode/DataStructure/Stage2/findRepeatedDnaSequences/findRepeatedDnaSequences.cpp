#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:
    int L=10;
    int R=4;
    int RL=pow(4,9);
    vector<string> findRepeatedDnaSequences(string s) {
        vector<int> num;
        vector<string> answer;
        unordered_map<long,int> map;
        for(auto x:s){
            switch(x){
                case 'A':
                    num.push_back(0);
                    break;
                case 'G':
                    num.push_back(1);
                    break;
                case 'C':
                    num.push_back(2);
                    break;
                case 'T':
                    num.push_back(3);
                    break;
            }
        }
        int left=0,right=0;
        long window=0;
        int size=s.size();
        while(right<size){
            window=R*window+num[right];
            right++;
            if(right-left==L){
                if(map.find(window)!=map.end()&&map[window]==1){
                    string temp;
                    for(int i=left;i<=right;i++){
                        temp.push_back(s[i]);
                    }
                    answer.push_back(temp);
                }
                map[window]++;
                window=window-RL*num[left];
                left++;
            }
        }
        return answer;
    }
};
main(){
    Solution s;
    string k="ACCCCCCCCCCCCCACCCCCCCCCCCCTGTGTGTGTGTTGGTGTGTGTGTGTGGG";
    vector<string> answer=s.findRepeatedDnaSequences(k);
    for(auto x:answer){
        cout<<x<<" ";
    }
}