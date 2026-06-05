class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> validTriplets{};

        // time complexity: O(nlogn), space complexity: O(1)
        std::sort(nums.begin(), nums.end());

        // time complexity: O(n^2), space complexity: O(1)
        for (size_t i{0}; i < nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int leftPtr{static_cast<int>(i) + 1};
            int rightPtr{static_cast<int>(nums.size()) - 1};
            while (leftPtr < rightPtr)
            {

                int sum = nums[i] + nums[leftPtr] + nums[rightPtr];

                if (sum < 0)
                {
                    ++leftPtr;
                }
                else if (sum > 0)
                {
                    --rightPtr;
                }
                else
                {
                    std::vector<int> validTriplet{nums[i], nums[leftPtr], nums[rightPtr]};
                    validTriplets.push_back(validTriplet);

                    while (leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr + 1])
                    {
                        ++leftPtr;
                    }

                    while (leftPtr < rightPtr && nums[rightPtr] == nums[rightPtr - 1])
                    {
                        --rightPtr;
                    }
                    ++leftPtr;
                    --rightPtr;
                }
            }
        }
        return validTriplets;
    }
};
