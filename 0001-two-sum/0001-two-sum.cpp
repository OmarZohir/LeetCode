class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        std::unordered_map<int,int> numMap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            // search if the complement has already been added into the map
            if (numMap.find(complement) != numMap.end()) {
                sol.push_back(numMap[complement]);
                sol.push_back(i);
                break;
            }
            numMap[nums[i]] = i; // Store the number and its index in the hashmap
        }
        return sol;
    }
};
