#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isBadVersion(int n){
        if (n >= 2) {
            return true;
        } else {
            return false;
        }
    }
    int firstBadVersion(int n) {
        int high=n;
        int low=1;
        int medium;
        while(high>low){
            medium=(high+low)/2;
            if(isBadVersion(medium)) high=medium-1;
            if(!isBadVersion(medium)) low=medium+1;
        }
        if(isBadVersion(high)&&isBadVersion(low))return low;
        else return high;
    }
};
main(){
    int n=2;
    Solution s;
    int answer=s.firstBadVersion(n);
    cout<<answer;
}