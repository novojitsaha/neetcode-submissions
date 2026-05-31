class Solution {
public:
    int lengthOfLongestSubstring(string s) {


        if (s.size() < 2)
            return s.size();

        int longestLength{1}, currentLength{1}, leftPtr{0}, rightPtr{1};
        std::unordered_map<char, int> charIdxMap{{s[leftPtr], leftPtr}};

        while (rightPtr < s.size())
        {
            if (charIdxMap.count(s[rightPtr]))
            {
                longestLength = std::max(currentLength, longestLength);
                leftPtr = std::max((charIdxMap[s[rightPtr]] + 1), leftPtr) ;
                charIdxMap[s[rightPtr]] = rightPtr;
                currentLength = rightPtr - leftPtr + 1;
                ++rightPtr;
            }
            else
            {
                charIdxMap.emplace(s[rightPtr], rightPtr);
                ++rightPtr;
                ++currentLength;
            }
        }

        return std::max(longestLength, currentLength);
    }
};
