class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};  // Return 1-based indices
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};  // If no solution is found, return an empty vector
    }
};