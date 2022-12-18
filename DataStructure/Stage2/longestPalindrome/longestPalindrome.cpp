#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int max_lenth=1;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<=i;j++){
                if(ispalind(s,j,i)){
                    max_lenth=max_lenth>i-j+1?max_lenth:i-j+1;
                }
            }
        }
        return max_lenth;
    }
    bool ispalind(string s,int left,int right){
        if(left>=right){
            return true;
        }
        else{
            if(s[left]!=s[right])return false;
            return ispalind(s,left+1,right-1);
        }
    }
};
main(){
    string s="sdnaAdsasdkmn";
        Solution a;
        cout<<a.longestPalindrome(s);
}