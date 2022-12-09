#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        vector<int> temp;//��¼��һ����ڶ��ε������������
        vector<int> first(1,1);
        temp.push_back(1);
        answer.push_back(temp);
        if(numRows==1)
            return answer;
        temp.push_back(1);
        answer.push_back(temp);
        if(numRows==2)//��1��2������ʹ���
            return answer;
        for(int i=2;i<numRows;i++)//��λ���
        {
            answer.push_back(first);
            for(int j=0;j<i-1;j++)
            {
                answer[i].push_back(answer[i-1][j]+answer[i-1][j+1]);
            }
            answer[i].push_back(1);
        }
        return answer;
    }
};
int main()
{
    vector<vector<int>> num;
    Solution answer;
    int level;
    cout<<"Please enter the number of levels: ";
    cin>>level;
    num=answer.generate(level);
    for(int i=0;i<num.size();i++)
    {
        for(int j=0;j<num[i].size();j++)
        {
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
}