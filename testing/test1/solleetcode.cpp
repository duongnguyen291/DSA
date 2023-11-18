class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int res = 0;
        while(l <r){
            if(res < abs(l-r)*min(height[l], height[r])){
                res = abs(l-r)*min(height[l], height[r]);
            }
            if(height[l] > height[r]){
                r--;
            }
            else l--;
        }
        return res;
    }
};