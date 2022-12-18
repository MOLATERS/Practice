#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fill(image,sr,sc,image[sr][sc],color);
        return image;
    }
    void fill(vector<vector<int>> &image,int sr,int sc,int original,int newcolor){
        if(!Isvalid(sr,sc,image))return;
        if(image[sr][sc]!=original)return;
        if(image[sr][sc]==-1)return;
        image[sr][sc]=-1;
        fill(image,sr-1,sc,original,newcolor);
        fill(image,sr+1,sc,original,newcolor);
        fill(image,sr,sc+1,original,newcolor);
        fill(image,sr,sc-1,original,newcolor);
        image[sr][sc]=newcolor;
    }
    bool Isvalid(int x,int y,vector<vector<int>> image){
        return x>=0&&y>=0&&image.size()>x&&image[x].size()>y;
    }
};