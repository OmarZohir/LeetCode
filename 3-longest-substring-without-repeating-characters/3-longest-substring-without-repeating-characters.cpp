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
            //search for element in the hash map
            if(hashset.find(s[b_ptr]) == hashset.end()){
                hashset.insert(s[b_ptr++]);
                max_len = hashset.size() > max_len? hashset.size(): max_len ;
            }
            else{
                hashset.erase(s[a_ptr]);
                a_ptr++;
                
            }
        }
        return max_len;
    }
};