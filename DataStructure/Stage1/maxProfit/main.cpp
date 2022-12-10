#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
//贪心算法，如果最小价钱和新增最小元素的差值与最大价钱和新增最大元素的差值比较
//如果是大小最小的部分（应该小于加入的值）算出来的差值，如果后者更小，所得到的值为正数
//如果是大小最大的部分（应该大于新加入的值）算出来的差值，如果后者更大，所得到的的值为正数
//用大小来决定确定哪一边
/*
    如果min不准确，max准确，则执行前一个选择，更新min
    如果min不准确，max不准确，min的偏差大则更新min，反之更新max
    如果min准确，max准确，min的偏差小则更新min,反之更新max
    如果min准确，max不准确，左边小右边大，更新max
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