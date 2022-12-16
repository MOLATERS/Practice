#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        int i=0,j=0;
        int size=intervals.size();
        vector<int> flag(size,0);
        Sort(intervals,0,size-1);
        while(i<size-1){
            i=j;
            j++;
            if(i<size-1){
                while(intervals[i][1]>intervals[j][0]){
                    count++;
                    j++;
                    if(j==size)break;
                }
            }
        }
        return count;
    }
    void  Sort(vector<vector<int>>& inter,int left,int right){
            if(left<right){
            int i=left;
            int j=right;
            int x=inter[i][0];
            int x2=inter[i][1];
            while(i<j){
                while(i<j&&inter[j][1]>=x2)
                    j--;
                if(i<j){
                    inter[i][0]=inter[j][0];
                    inter[i][1]=inter[j][1];
                    i++;
                }
                while(i<j&&inter[i][1]<x2)
                    i++;
                if(i<j){
                    inter[j][0]=inter[i][0];
                    inter[j][1]=inter[i][1];
                    j--;
                }
            }
            inter[i][0]=x;
            inter[i][1]=x2;
            Sort(inter,left,i-1);
            Sort(inter,i+1,right);
        }
    }
};
main(){
    vector<vector<int>> inter={{1,2},{2,3},{3,4},{1,3}};
    Solution s;
    int answer;
    answer=s.eraseOverlapIntervals(inter);
    cout<<answer;
    return 0;
}