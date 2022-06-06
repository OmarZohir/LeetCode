class Solution {
public:
    //k: target value of sum
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefix_sum = 0;
        unordered_map<int,int> prefix_table;
        prefix_table[0] = 1;
        
        //example: if we have a prefix sum of 28, but we only have a target of 18;
        //we need to find and cancel a range with a prefix sum = 10
        //if that range exists n times then we need to increase
        // the count of the range with sum equal to target n times as well (18 in this case)
        for(int i=0; i < (int) nums.size(); i++){
            prefix_sum += nums[i];
            
            // increase the count by the number of times the target value has been seen
            // by searching if there is an entry equal to prefix_sum - target
            // if it exists, add the number of times this entry occurred to the count 
            //(i.e., how many different ranges with value equal to k can be formed upto index i)
            if(prefix_table.count(prefix_sum - k))
                count += prefix_table[prefix_sum - k];
            
            // increase the value of the number of times the prefix sum occurred
            ++prefix_table[prefix_sum];
            
        }
        return count;
    }
};