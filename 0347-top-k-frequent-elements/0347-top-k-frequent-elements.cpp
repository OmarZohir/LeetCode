
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Step 1: Count the frequencies using an unordered_map
        std::unordered_map<int, int> count_map;
        std::map<int, std::vector<int>> count_as_key;
        std::vector<int> result;

        for (int num : nums) {
            count_map[num]++;
        }

        // Step 2: Fill the count_as_key map
        for (auto& entry : count_map) {
            count_as_key[entry.second].push_back(entry.first);
        }

        // Step 3: Iterate over the count_as_key map in reverse order
        for (auto it = count_as_key.rbegin(); it != count_as_key.rend() && k > 0; ++it) {
            for (int val : it->second) {
                if (k > 0) {
                    result.push_back(val);
                    k--;
                } else {
                    break;
                }
            }
        }

        return result;
    }
};