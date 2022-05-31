class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Solve as a sliding window problem (two sliding pointers)
        int a_ptr = 0;
        int b_ptr = 0;
        int max_len = 0;
        unordered_set<char> hashset;
        
        //Until the end of the 
        while(b_ptr < s.length()){
            //search for a duplicate of the element is found in the hash set
            if(hashset.find(s[b_ptr]) == hashset.end()){
                // insert element at right-hand ptr to the hash set
                hashset.insert(s[b_ptr]);
                b_ptr++;
                //max function, because leetcode giving me error when using max function
                max_len = hashset.size() > max_len? hashset.size(): max_len ;
            }
            else{
                // erase the element at the left-hand ptr from the hash set when a duplicate is found
                hashset.erase(s[a_ptr]);
                a_ptr++;
                
            }
        }
        return max_len;
    }
};