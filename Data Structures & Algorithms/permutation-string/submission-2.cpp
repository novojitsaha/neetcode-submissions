#include <array>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s2.size() < s1.size())
        {
            return false;
        }

        int n1 = static_cast<int>(s1.size()); // window size
        int n2 = static_cast<int>(s2.size());

        std::array<int, 26> s1CharFreq{0};
        std::array<int, 26> s2CharFreq{0};

        // populate s1 character frequency map;
        for (int i{0}; i < n1; ++i)
        {
            ++s1CharFreq[s1[i] - 'a'];
        }

        int left{0};

        for (int right{0}; right < n2; ++right)
        {
            s2CharFreq[s2[right] - 'a']++;

            if ((right - left + 1) == n1)
            {
                if (s1CharFreq == s2CharFreq)
                {
                    return true;
                }
                s2CharFreq[s2[left] - 'a']--;
                ++left;
            }
        }
        return false;
    }
};
