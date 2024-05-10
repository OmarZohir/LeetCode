class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        unordered_map<char, int> s_map, t_map;
        for (int i = 0; i < s.length(); i++){
            s_map[s[i]] += 1;
            t_map[t[i]] += 1;
        }

        if (s_map == t_map)
            return true;
        
        else
            return false;
    }
};