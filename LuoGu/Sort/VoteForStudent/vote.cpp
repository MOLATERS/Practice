#include <iostream>
#include <vector>
using namespace std;
int m,n;
int main(){
    cin>>n>>m;
    // vector<int> cache(m,0);
    int cache[200000]={0};
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        cache[temp]++;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<cache[i];j++){
            cout<<i<<" ";
        }
    }
    return 0;
}