#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        int i=0,j=1;
        int size=intervals.size();
        vector<int> flag(size,0);
        quickSort1(intervals,0,size-1);
        while(i<size-1){
            int temp=i;
            while(intervals[i][0]==intervals[i+1][0])i++;
            if(temp!=i)
            quickSort2(intervals,temp,i);
            i++;
        }
        for(i=0;i<size-1&&j<size-1;){
            while(intervals[i][0]==intervals[i+1][0]){
                flag[i]++;
                i++;
            }
            j=i;
            j++;
            while(intervals[i][1]>intervals[j][0]){
                flag[j]++;
                j++;
            }
            i=j;
        }
        for(int i=0;i<size;i++){
            if(flag[i])count++;
        }
        return count;
    }
    void quickSort1(vector<vector<int>>& inter,int left,int right){
        if(left<right){
            int i=left;
            int j=right;
            int x=inter[i][0];
            int x2=inter[i][1];
            while(i<j){
                while(i<j&&inter[j][0]>=x)
                    j--;
                if(i<j){
                    inter[i][0]=inter[j][0];
                    inter[i][1]=inter[j][1];
                    i++;
                }
                while(i<j&&inter[i][0]<x)
                    i++;
                if(i<j){
                    inter[j][0]=inter[i][0];
                    inter[j][1]=inter[i][1];
                    j--;
                }
            }
            inter[i][0]=x;
            inter[i][1]=x2;
            quickSort1(inter,left,i-1);
            quickSort1(inter,i+1,right);
        }
    }
    void  quickSort2(vector<vector<int>>& inter,int left,int right){
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
            quickSort2(inter,left,i-1);
            quickSort2(inter,i+1,right);
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