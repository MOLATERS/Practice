#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            Reverse(matrix[i]);
        }
    }
    void swap(int &a,int &b){
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    void Reverse(vector<int> &m){
        int head=m.size()-1;
        int tail=0;
        while(head>tail){
            swap(m[head],m[tail]);
            head--;
            tail++;
        }
    }
};