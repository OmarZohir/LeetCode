class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        //check if each letter in each word has the same count
        unordered_map<char, int> map_word1, map_word2;
        //for each word, add each letter, and its count
        for(int i = 0; i < s.length(); i++){
            if(!map_word1.count(s[i]))
                map_word1.insert({s[i],1});
            else
                map_word1[s[i]]++;
            
            if(!map_word2.count(t[i]))
                map_word2.insert({t[i],1});
            else
                map_word2[t[i]]++;
        }
        //the == operator is overloaded for unordered_map since C++11
        return (map_word1 == map_word2);
    }
};