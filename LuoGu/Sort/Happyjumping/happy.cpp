#include <iostream>
using namespace std;
class Solution {
public:
    int n;
    int pre;
    int current;
    long num[100000]={0};
    bool isjolly(){
        cin>>n;
        cin>>pre;
        for(int i=0;i<n-1;i++){
            cin>>current;
            int temp=abs(current-pre);
            num[temp]++;
            if(num[temp]>1)return false;
            pre=current;
        }
        for(int i=1;i<=n-1;i++){
            if(num[i]==0)return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    if(s.isjolly())printf("Jolly");
    else printf("Not jolly");
    return 0;
}