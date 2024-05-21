class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int max_count = 0;

        for (int num : nums) {
            // Check if this is the start of a sequence
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int count = 1;

                // Count the length of the sequence
                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num += 1;
                    count += 1;
                }

                // Update the maximum sequence length found
                max_count = std::max(max_count, count);
            }
        }

        return max_count;
    }
};