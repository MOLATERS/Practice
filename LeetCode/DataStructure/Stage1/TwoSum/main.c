#include <stdlib.h>
#include <stdio.h>
typedef struct tree{//���������
    struct tree* lchild;
    struct tree* rchild;
    int data;
    int index;
}tree;
tree* CreateST(tree* T,int num,int index)//�������������
{
    if(T==NULL)
    {
        T=(tree*)malloc(sizeof(tree));
        if(T==NULL)return NULL;
        T->lchild=NULL;
        T->rchild=NULL;
        T->data=num;
        T->index=index;
    }
    else
    {
        if(num<T->data)
        T->lchild=CreateST(T->lchild,num,index);
        else if(num>T->data)
        T->rchild=CreateST(T->rchild,num,index);
        else if(num==T->data)return T;
    }
    return T;
}
int Find(tree* T,int num)//���Ҷ��������
{
    if(T==NULL)
    {
        return -1;
    }
    else
    {
        if(T->data==num)
        return T->index;
        else if(T->data>num)
        return Find(T->lchild,num);
        else
        return Find(T->rchild,num);
    }
}
int* twoSum(int* nums, int numsSize, int target){
    tree* T;
    int answer;
    int* p=(int*)malloc(sizeof(int)*2);
    for(int i=0;i<numsSize;i++)
    {
        T=CreateST(T,nums[i],i);//��������
    }
    for(int i=0;i<numsSize;i++)
    {
        answer=Find(T,target-nums[i]);//�ҵ���Ӧ�������±�
        if(answer!=-1&&answer<i)//�����±�λ�ù�ϵ
        {
            p[0]=answer;
            p[1]=i;
            break;
        }
        else if(answer!=-1&&answer>i)
        {
            p[0]=i;
            p[1]=answer;
            break;
        }
    }
    return p;
}
int main(){
    int p[4]={3,11,3,15};
    int* q=NULL;
    q=twoSum(p,4,26);
    printf("%d,%d",q[0],q[1]);
    return 0;
}