class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        out.resize(nums.size());

        //prefix pass
        // out[i] = pre[i-1] * post[i+1];
        out[0] = 1;
        int pre = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            out[i] = pre;
            pre*= nums[i];
        }

        //postfix pass
        int post = 1;
        for (int i = nums.size()-1; i >= 0; --i){
            out[i] *=post;
            post *= nums[i];
        } 

        return out;
    }
};