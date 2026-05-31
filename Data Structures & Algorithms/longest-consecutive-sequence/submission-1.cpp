class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
                std::unordered_set<int> set;

        // t: O(n), s:O(n)
        for (const int &i : nums)
        {
            set.insert(i);
        }

        // num is start if num - 1 doesn't exist
        std::vector<int> starts;
        starts.reserve(nums.size());

        // t: O(n), s:O(n)
        for (const int &i : nums)
        {
            if (!set.count(i - 1))
            {
                starts.push_back(i);
            }
        }

        int longest{0};
        // t: O(n), s:O(n)
        for (const int &s : starts)
        {
            int current = s;
            int currentLongest{1};
            while (true)
            {
                current++;
                if (!set.count(current))
                {
                    break;
                }
                currentLongest++;
            }

            if (currentLongest > longest)
            {
                longest = currentLongest;
            }
        }

        return longest;
    }
};
