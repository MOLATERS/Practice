#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool cmp(string a,string b){
	return a+b>b+a;
}

int main(){
	int n;
	cin >> n;
	string a[20];
	for (int i = 0;i<n;i++) cin >> a[i];
	std::sort(a,a+n,cmp);
	for (int i = 0;i<n;i++){
		cout << a[i];
	}
	cout << endl;
	return 0;
}