class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> charIdxMap;
        int longestLength{0};

        int currentLength{0};
        for (size_t i{0}; i < s.size(); i)
        {
            if (charIdxMap.count(s[i]))
            {
                i = charIdxMap[s[i]] + 1;
                if (currentLength > longestLength)
                {
                    longestLength = currentLength;
                }
                currentLength = 0;
                charIdxMap.clear();
            }
            else
            {
                charIdxMap.emplace(s[i], i);
                ++currentLength;
                ++i;
            }
        }

        return std::max(longestLength, currentLength);
    }
};
