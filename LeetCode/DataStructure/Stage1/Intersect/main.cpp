#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        int size;
        int temp1[1001]={0};
        int temp2[1001]={0};
        for(int i=0;i<nums1.size();i++)
        {
            temp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            temp2[nums2[i]]++;
        }
        for(int i=0;i<=1000;i++)
        {
            if(temp1[i]!=0&&temp2[i]!=0)
            {
                size=(temp1[i]<temp2[i])?temp1[i]:temp2[i];
                for(int j=0;j<size;j++)
                {
                    answer.push_back(i);
                }
            }
        }
        return answer;
    }
};

main()
{
    int count=0;
    vector<int> nums1(9);
    for(int i=0;i<9;i++)
    {
        nums1[i]=count++;
    }
    vector<int> nums2(nums1);
    Solution a;
    vector<int> nums3=a.intersect(nums1,nums2);
    for(int i=0;i<18;i++)
    std::cout<<nums3[i];
}