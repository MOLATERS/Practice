#include <iostream>
#include <algorithm>
using namespace std;
int high[20005];
bool cmp(int a,int b)//使用sort排序定义从大到小
{
	return a>b;
}
int main()
{
	int n,b;
	cin>>n>>b;
	for(int i=0;i<n;i++)
	{
		cin>>high[i];
	}
	sort(high,high+n,cmp);//sort一键排序
	int sum=0,ans=0;
	while(sum<b)//只要高度不够就继续叠
	{
		sum+=high[ans];
		ans++;
	}
	cout<<ans;
	return 0;
}