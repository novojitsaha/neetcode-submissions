class Solution {
public:
    int characterReplacement(string s, int k) {
    std::unordered_map<char, int> charFreqMap;

    int leftPtr{0}, topFreq{0}, longestLength{0};

    for (int rightPtr{0}; rightPtr < s.size(); ++rightPtr)
    {
        charFreqMap[s[rightPtr]]++;
        topFreq = std::max(topFreq, charFreqMap[s[rightPtr]]);

        if ((rightPtr - leftPtr + 1) - topFreq > k)
        {
            charFreqMap[s[leftPtr]]--;
            leftPtr++;
        }
        longestLength = std::max(longestLength, (rightPtr - leftPtr + 1));
    }

    return longestLength;
    }
};
