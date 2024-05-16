class Solution {
public:
    struct VectorHash {
        template <typename T>
        size_t operator()(const std::vector<T>& v) const {
            size_t seed = v.size();
            for (const auto& element : v) {
                seed ^= std::hash<T>()(element) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHash> anagrams_map;
        
        for (auto& str: strs){
            vector<int> count(26, 0);
            for (char& c: str){
                int index = c - 'a';
                count[index]++;
            }
            anagrams_map[count].push_back(str);
        }
        
        vector<vector<string>> output;
        for (const auto& pair : anagrams_map) {
            output.push_back(pair.second);
        }
        
        return output;
    }
};