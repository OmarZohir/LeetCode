class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // naive solution
        int max_so_far = nums.back(); // assume largest number is the one on the right
        int max_diff = -1 ; // return -1 if no max difference matching criteria found
        // Keep on searching for the max number from the right towards the left (because of the criteria)
        for (int i = nums.size()-2; i >= 0; i--){
            if (nums[i] < max_so_far){
                max_diff = max_diff > (max_so_far - nums[i])? max_diff : (max_so_far - nums[i]);
            }
            max_so_far = max(max_so_far, nums[i]);
        }  
        return max_diff;
    }
};