class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        std::vector<int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            int k = target - nums[i];
            // Search if k exists in the rest of the vector
            it = std::find(nums.begin(), nums.end(), k);
            if (it != nums.end()) {
                int index = it - nums.begin();
                // Ensure that the same element is not used twice
                if (index != i) {
                    sol.push_back(i);
                    sol.push_back(index);
                    break; // Assuming there is exactly one solution
                }
            }
        }
        return sol;
    }
};
