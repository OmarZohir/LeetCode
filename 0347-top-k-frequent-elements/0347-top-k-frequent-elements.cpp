class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Step 1: Count the frequencies using an unordered_map
        std::unordered_map<int, int> count_map;
        for (int num : nums) {
            count_map[num]++;
        }

        // Step 2: Use a min-heap to keep track of the top k elements
        auto comp = [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> min_heap(comp);

        for (const auto& entry : count_map) {
            min_heap.push(entry);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // Step 3: Extract the elements from the heap
        std::vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().first);
            min_heap.pop();
        }

        // The min-heap gives us the elements in ascending order of their frequency,
        // so we need to reverse the result to have the most frequent elements first.
        std::reverse(result.begin(), result.end());

        return result;
    }
};