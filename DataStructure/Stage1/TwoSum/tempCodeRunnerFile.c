typedef struct tree{//查找树结点
    struct tree* lchild;
    struct tree* rchild;
    int data;
    int index;
}tree;
tree* CreateST(tree* T,int num,int index)//构建二叉查找树
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
int Find(tree* T,int num)//查找二叉查找树
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
        T=CreateST(T,nums[i],i);//建树过程
    }
    for(int i=0;i<numsSize;i++)
    {
        answer=Find(T,target-nums[i]);//找到对应的数字下标
        if(answer!=-1&&answer<i)//调整下标位置关系
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