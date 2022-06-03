#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> val_idx_mp;
        int otherVal;
        vector<int> indices(2);
       
        for (int curIdx = 0; curIdx < nums.size(); curIdx++){
            indices[0] = curIdx; 
            otherVal = target - nums[curIdx];
            //check before adding the element into the hashmap
            if(val_idx_mp.count(otherVal)){
                return vector<int>({curIdx,val_idx_mp[otherVal]});
            }     
            val_idx_mp[nums[curIdx]] = curIdx;
        }        
        return indices;
    }
};