class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_prod;
        vector<int> suffix_prod;
        prefix_prod.resize(nums.size());
        suffix_prod.resize(nums.size());
        //initialize prefix prod start and suffix prod end
        prefix_prod[0] = nums[0];
        int end_idx = nums.size()-1; 
        suffix_prod[end_idx] = nums[end_idx];
        //get the prefix prod array
        for (int i =1; i < nums.size(); ++i){
            prefix_prod[i] = prefix_prod[i-1]*nums[i];
            suffix_prod[end_idx-i] = suffix_prod[end_idx-i+1]*nums[end_idx-i];
        }

        vector<int> output;
        output.resize(nums.size());
        output[0] = suffix_prod[1];
        output[end_idx] = prefix_prod[end_idx-1];
        for (int i=1; i < nums.size() -1; i++){
            output[i] = prefix_prod[i-1]*suffix_prod[i+1];
        }
        return output;
    }
};