#include <iostream>
#include <algorithm>
using namespace std;
int high[20005];
bool cmp(int a,int b)//ʹ��sort������Ӵ�С
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
	sort(high,high+n,cmp);//sortһ������
	int sum=0,ans=0;
	while(sum<b)//ֻҪ�߶Ȳ����ͼ�����
	{
		sum+=high[ans];
		ans++;
	}
	cout<<ans;
	return 0;
}