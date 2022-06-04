class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // naive solution
        int maxIdx = -1;
        int maxNum = 0;
        int maxDiff;
        for (int i = nums.size()-1; i > -1 ; i--){
            if (i > 0 && nums[i] > maxNum){
                maxIdx = i; 
                maxNum = nums[i];
            }
            else if (maxNum - nums[i] > maxDiff)
                maxDiff = maxNum-nums[i];
        }  
        if (maxDiff <= 0)
            return -1;
        else
            return maxDiff;
    }
};