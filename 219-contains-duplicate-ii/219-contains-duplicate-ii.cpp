class Solution {
public:
    //FIXED SLIDING WINDOW PROBLEM
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        //count of number of elements in the window k
        //HASH SET IS A BETTER FIT HERE, BUT I AM NOT GOING TO change my solution
        unordered_map<int, int> count_table_k;
        // loop over the first k elements in the array from the left-hand side
        for (int i = 0; i <= k && i < nums.size(); i++){
            // if the element is seen for the first time, add it to the table
            if(!count_table_k.count(nums[i]))
                count_table_k.insert({nums[i],1});
            else
                //if the element has already been seen twice in that window, return true
                return true;
        }
        
        //end: end of the sliding window
        //start moving the sliding window by step of 1
        for(int end = k+1; end < nums.size(); end++){
            //reduce the count for the element that WAS at the beginning of the sliding window 
            count_table_k.erase(nums[end-k-1]);
            //check if the new element to be added is already in the count table
            if(count_table_k.count(nums[end]))
                //if it's already in the table add it
                return true;
            else
                //if not, add it
                count_table_k.insert({nums[end],1});
        }
        return false;
    }
};