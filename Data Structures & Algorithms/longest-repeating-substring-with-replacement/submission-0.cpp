class Solution {
public:
    int characterReplacement(string s, int k) {
     std::unordered_map<char, int> freq;
    int left = 0, maxCount = 0, best = 0;

    for (int right = 0; right < static_cast<int>(s.size()); ++right) {
        maxCount = std::max(maxCount, ++freq[s[right]]);

        // If more than k chars need replacement, shrink from the left
        while ((right - left + 1) - maxCount > k) {
            --freq[s[left]];
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
    }
};
