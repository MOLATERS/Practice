#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int num2;
        int size=numbers.size();
        vector<int> answer;
        for(int i=0;numbers[i]<=target/2;i++){
            num2=halfsearch(numbers,i+1,size-1,target-numbers[i]);
            if(num2!=-1){
                answer.push_back(i);
                answer.push_back(num2);
                return answer;
            }
        }
        return answer;
    }
    // int FindLow(vector<int> &numbers, int target){
    //     int num;
    //     while(target>numbers[num])num++;
    //     return num;
    // }
    int halfsearch(vector<int> &numbers, int low, int high,int target){
        while(high>=low){
            int mid=(high+low)/2;
            if(numbers[mid]>target) high=mid-1;
            else if(numbers[mid]<target) low=mid+1;
            else return mid;
        }
        return -1;
    }
};
main(){
    vector<int>num;
    num.push_back(0);
    num.push_back(0);
    num.push_back(2);
    // num.push_back(3);
    num.push_back(3);
    num.push_back(4);
    Solution s;
    vector <int> answer;
    answer=s.twoSum(num,6);
    if(!answer.empty())
    cout<<answer[0]<<" "<<answer[1];
    return 0;
}