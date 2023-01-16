#include <iostream>
using namespace std;
class Solution{
public:
    int Length[200000]={0};
    int count=0;
    bool isbigger(int a,int b){
        return a>=b;
    }
    void swap(int& a,int& b){
        int temp=a;
        a=b;
        b=temp;
        count++;
    }
    void sort(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(isbigger(Length[j],Length[j+1]))
                swap(Length[j],Length[j+1]);
            }
        }
    }
    void train(){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>Length[i];
        }
        sort(n);
        cout<<count;
    }
};
int main(){
    Solution s;
    s.train();
    return 0;
}