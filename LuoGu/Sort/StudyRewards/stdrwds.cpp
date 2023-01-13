#include <iostream>
using namespace std;
int count=0;
struct Student{
    int index; 
    int sum;
    int chinese;
    struct Student* left;
    struct Student* right;
    Student():sum(0),index(0),chinese(0),left(nullptr),right(nullptr){}
    Student(int x,int y,int z):index(x),sum(y),chinese(z),left(nullptr),right(nullptr){}
};
void CreateTree(Student*&head,Student*&temp){
    if(head==nullptr){
        head=temp;
        return;
    }
    if(head->sum>temp->sum){
        CreateTree(head->left,temp);
    }
    else if(head->sum<temp->sum){
        CreateTree(head->right,temp);
    }
    else{
        if(head->chinese>temp->chinese){
            CreateTree(head->left,temp);
        }
        else if(head->chinese<temp->chinese){
            CreateTree(head->right,temp);
        }
        else{
            if(head->index<temp->index){
            CreateTree(head->left,temp);
            }
            else{
                CreateTree(head->right,temp);            
            }
        }
    }
}
class Solution{
public:
    int count=0;
    void preorder(Student* head){
        if(count==5)exit(0);
        if(head==nullptr)return;
        preorder(head->right);
        cout<<head->index<< " "<<head->sum<<endl;
        count++;
        preorder(head->left);
    }
};
// void preorder(Student* head){
//     int count=0;
//     Student* stack[20000];
//     int top=-1;
//     if(head==nullptr)return;
//     while(head->right!=nullptr){
//         stack[++top]=head;
//         head=head->right;
//     }
//     cout<<head->index<< " "<<head->sum<<endl; 
//     count++;
//     while(top>-1&&count<5){
//         head=stack[top];top--;
//         cout<<head->index<< " "<<head->sum<<endl;count++;
//         if(head->left!=nullptr){
//             head=head->left;
//             stack[++top]=head;
//         while(head->right!=nullptr){
//             head=head->right;
//             stack[++top]=head;
//         }
//         }
//     }
// }
int main(){
    int n;
    cin>>n;
    Student* head=nullptr;
    for(int i=0;i<n;i++){
        int temp1;
        int temp2;
        int temp3;
        cin>>temp1>>temp2>>temp3;
        Student* temp=new Student(i+1,temp1+temp2+temp3,temp1);
        CreateTree(head,temp);
    }
    Solution s;
    s.preorder(head);
    return 0;
}

