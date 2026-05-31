class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // {complement: index}
        std::unordered_map<int, int> hashMap;

        for (size_t idx{0}; idx < nums.size(); ++idx)
        {

            int complement = target - nums[idx];

            // hash set lookup: O(1)
            if (hashMap.count(complement))
            {

                int minIdx = std::min(static_cast<int>(idx), hashMap[complement]);
                int maxIdx = std::max(static_cast<int>(idx), hashMap[complement]);

                return std::vector<int>{minIdx, maxIdx};
            }

            hashMap[nums[idx]] = idx;
        }

        return std::vector<int>{-1, -1}; // no such pairs exist
    }
};
