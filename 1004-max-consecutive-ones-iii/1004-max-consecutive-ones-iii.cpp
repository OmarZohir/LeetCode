class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_length = 0;
        for (int start = 0 ,end = 0, zeros = 0; end < nums.size(); end++){
            //if it's zero
            if(nums[end] == 0)
                zeros++;
            //if zeros > k, invalid window, shift from the left-hand side until you get a valid window
            // that satisfies the condition
            while(zeros > k){
                if(nums[start] == 0)
                    zeros--;
                start++;
            }
            max_length = max(max_length, end-start+1); // end-start+1 = length of the current window
        }
       
        return max_length;
    }
};