#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
//̰���㷨�������С��Ǯ��������СԪ�صĲ�ֵ������Ǯ���������Ԫ�صĲ�ֵ�Ƚ�
//����Ǵ�С��С�Ĳ��֣�Ӧ��С�ڼ����ֵ��������Ĳ�ֵ��������߸�С�����õ���ֵΪ����
//����Ǵ�С���Ĳ��֣�Ӧ�ô����¼����ֵ��������Ĳ�ֵ��������߸������õ��ĵ�ֵΪ����
//�ô�С������ȷ����һ��
/*
    ���min��׼ȷ��max׼ȷ����ִ��ǰһ��ѡ�񣬸���min
    ���min��׼ȷ��max��׼ȷ��min��ƫ��������min����֮����max
    ���min׼ȷ��max׼ȷ��min��ƫ��С�����min,��֮����max
    ���min׼ȷ��max��׼ȷ�����С�ұߴ󣬸���max
*/
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int max=prices[prices.size()-1];
        int p,q;
        for(p=0,q=prices.size()-1;p<=q;)
        {
            if(min-prices[p]>prices[q]-max)
            {min=min<prices[p]?min:prices[p];p++;}
            else
            {max=max>prices[q]?max:prices[q];q--;}
        }
        return max-min;
    }
};