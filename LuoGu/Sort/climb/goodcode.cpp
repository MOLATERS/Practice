#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
	double x,y,z;
	bool operator<(const Node &other)const{//����С�������
		return z<other.z;
	}
} a[50050];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a,a+n);//ÿ����߶ȴ�С��������
	double ans=0;
	double cx=a[0].x,cy=a[0].y,cz=a[0].z;
	for(int i=1;i<n;i++){
		ans+=sqrt(abs(cx-a[i].x)*abs(cx-a[i].x)+abs(cy-a[i].y)*abs(cy-a[i].y)+abs(cz-a[i].z)*abs(cz-a[i].z));//�����ŷ����þ���
		cx=a[i].x;
		cy=a[i].y;
		cz=a[i].z;
	}
	printf("%.3lf\n",ans);//���������λС��
	return 0;//�����Ľ���
} 