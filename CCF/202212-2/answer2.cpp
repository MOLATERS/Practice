#include <iostream>
using namespace std;

struct
{
	int form=0;//�ȵ���
	int day=0;//����
	int start=1;//����
	int last_start=0;//���� 
}course[105]; 

int main()
{
	int max=-1;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>course[i].form;
	}
	for(int i=0;i<m;i++)
	{
		cin>>course[i].day;
	}
	for(int i=0;i<m;i++)
	{
		if(course[i].form != 0)
		{
			course[i].start = course[course[i].form-1].start+course[course[i].form-1].day;//���ſε����翪ʼʱ��Ϊ�ȵ����������ʱ��
		}
		cout<<course[i].start<<" ";//������翪ʼʱ�� 
		if((course[i].day+course[i].start)>max)//�ж��Ƿ�������� 
			max=course[i].day+course[i].start-1;		
	}
	
	
	
	if(max<=n)//���Ͼ���� 
	{
		cout<<endl;
		for(int i=m-1;i>=0;i--)
		{
			if(course[i].last_start==0)
				course[i].last_start=n-course[i].day+1;
			if(course[i].form != 0)
			{
				int temp = course[i].last_start-course[course[i].form-1].day ;
				if(course[course[i].form-1].last_start == 0)
				{
					course[course[i].form-1].last_start = temp ;
				}
				else
				{
					course[course[i].form-1].last_start = min(temp,course[course[i].form-1].last_start);
				}
			}
		
		}
		
		for(int i=0;i<m;i++)
		{
			cout<<course[i].last_start<<" ";
		}
	}
	return 0;
}

/*
14 7
0 1 0 3 2 3 0
2 1 6 3 10 4 3
*/

/*
51 5
0 1 2 3 4
10 10 10 10 10

*/
