class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start, end;
        start = end = 0;
        int max_length = 0;
        int cur_length = 0;
        while (end < nums.size()){
            //if 1, increase count of max substr length
           if(nums[end]){
               cur_length++;
               end++;
           }
            else{
                //if 0 and we have already flipped maximum number of 0s
                if(k == 0){
                    //check/unflip the previous first element
                    if(nums[start] == 0){
                        k++;
                    }
                    cur_length--;
                    start++;
                        
                }
                    
                // if we have still some room for flipping 0s
                else{
                    cur_length++;
                    k--;
                    end++;
                }     
            }
             max_length = max(max_length, cur_length);
        }
        return max_length;
    }
};