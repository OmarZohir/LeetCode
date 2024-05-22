class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort the input array
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        vector<unordered_map<int,int>> sol_vec_of_maps;
        for (int i = 0; i < nums.size(); ++i){
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int target = -nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while (left < right){
                if (nums[left] + nums[right] > target)
                    right--;
                else if (nums[left] + nums[right] < target)
                    left++;
                else{
                    sol.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while(nums[left] == nums[left-1] && left < right) 
                        left++;
                }                    
                
            }
        }
        return sol;
    }
};