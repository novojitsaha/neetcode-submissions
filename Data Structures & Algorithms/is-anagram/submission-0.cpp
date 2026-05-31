class Solution {
public:
    bool isAnagram(string s, string t) {
    
        if (s.length() != t.length()) return false;
        
        int freq[26] = {0};

        for (const char c: s){
            freq[c - 'a']++;
        } 

        for (const char c: t){
            freq[c - 'a']--;
        }

        for (const int i: freq){
            if (i > 0) return false;
        }
        return true;

    }
};
