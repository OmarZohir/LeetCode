class Solution {
public:
    int maxArea(vector<int>& height) {
        int lIdx = 0;
        int rIdx = height.size()-1; 
        int maxArea = -1;
        while (lIdx < rIdx){
            maxArea = max(maxArea, min(height[lIdx],height[rIdx]) * (rIdx - lIdx)) ;
            if (height[lIdx] < height[rIdx])
                lIdx++;
            else
                rIdx--;
            
        }
        return maxArea;
    }
};