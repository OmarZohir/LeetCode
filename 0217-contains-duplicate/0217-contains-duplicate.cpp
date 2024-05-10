class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numCount;
        for (int& num: nums){
            numCount[num] += 1;
            if (numCount[num] > 1)
                return true; 
        }
        return false;
    }
};