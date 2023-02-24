#include <iostream>
using namespace std;
int main(){
    long long n;
    long long m;
    long long z=0;
    long long k=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            z=z+min(i,j);
            k=k+j*i;
        }
    }
    cout<<z<<" "<<k-z;
}