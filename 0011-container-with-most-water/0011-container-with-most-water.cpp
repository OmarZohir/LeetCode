class Solution {
public:
    int maxArea(vector<int>& height) {
    int maxArea = 0;
    int left = 0;
    int right = height.size() -1;
    int Area;
    while (left < right){
        int smallerSide = min(height[left],height[right]);
        Area = smallerSide * (right - left);
        if (Area > maxArea)
            maxArea = Area;
        if (height[left] == smallerSide)
            left++;
        else 
            right--;
    }

    return maxArea;
    }
};