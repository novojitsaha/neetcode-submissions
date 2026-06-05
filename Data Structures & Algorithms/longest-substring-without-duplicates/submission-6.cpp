class Solution {
   public:
    int lengthOfLongestSubstring(string& s) {
        int n = static_cast<int>(s.size());

        std::unordered_map<char, int> seen;
        seen.reserve(26);  // english alphabet has 26 letters

        int longest{0};

        if (n <= 1) {
            return n;
        }

        int left{0};

        for (int right{0}; right < n; ++right) {
            if (seen.count(s[right])) {
                left = std::max(left, seen[s[right]] + 1);
                seen[s[right]] = right;
                longest = std::max(longest, right - left + 1);
            } else {
                longest = std::max(longest, right - left + 1);
                seen.insert({s[right], right});
            }
        }

        return longest;
    }
};
