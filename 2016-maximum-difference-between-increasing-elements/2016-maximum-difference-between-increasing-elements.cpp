class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // naive solution
        int maxDiff = -1;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); j++){
                if((nums[j] - nums[i]) > maxDiff){
                    maxDiff = nums[j] - nums[i];
                }
            }
        }    
        if (maxDiff == 0)
            return -1;
        else
            return maxDiff;
    }
};