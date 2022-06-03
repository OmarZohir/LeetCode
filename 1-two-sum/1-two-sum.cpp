#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { 
        int otherVal;
        vector<int> indices(2);
        std::vector<int>::iterator it;
        
        for (int curIdx = 0; curIdx < nums.size(); curIdx++){
            indices[0] = curIdx; 
            otherVal = target - nums[curIdx];
            it = std::find(nums.begin()+curIdx+1,nums.end(),otherVal);
            if(it != nums.end()){
                indices[1] = it - nums.begin();
                return indices;
            }
        }        
        return indices;
    }
};