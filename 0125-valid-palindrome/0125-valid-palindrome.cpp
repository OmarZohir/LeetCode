class Solution {
public:
    bool isPalindrome(std::string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while (i < j) {
            // Skip non-alphanumeric characters
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            
            // Convert to lowercase for case-insensitive comparison
            if (tolower(s[i]) != tolower(s[j])) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};