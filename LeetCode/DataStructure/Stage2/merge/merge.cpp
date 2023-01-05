#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        unordered_map<int,int> hash;
        vector<vector<int>> answer;
        int pointer=0;
        int size_inter=intervals.size();
        for(int i=0;i<size_inter;i++){
            if(intervals[i][0]==intervals[i][1])hash[intervals[i][0]]++;
            for(int j=intervals[i][0];j<intervals[i][1];j++)
            {
                if(hash[j]==0)
                hash[j]++;
                else
                continue;
            }
        }
        while(pointer<hash.size()){
            vector<int> temp;
            bool find=false;
            int head=pointer;
            while(hash[pointer]){
                pointer++;
                find=true;
            }
            if(find){
                temp.push_back(head);
                temp.push_back(pointer);
                answer.push_back(temp);
            }
            else{
                pointer++;
            }
        }
        return answer;
    }
};
main(){
    vector<vector<int>> num;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(4);
    num.push_back(temp);
    vector<int> temp2;
    temp2.push_back(0);
    temp2.push_back(0);
    num.push_back(temp2);
    Solution s;
    vector<vector<int>> answer;
    answer=s.merge(num);
    return 0;
}