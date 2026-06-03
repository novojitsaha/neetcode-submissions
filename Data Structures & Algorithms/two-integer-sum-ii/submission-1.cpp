class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 2)
        {
            return std::vector<int>{1, 2};
        }

        int leftPtr{0};
        int rightPtr{static_cast<int>(nums.size()) - 1};

        while ((leftPtr < rightPtr) && (nums[leftPtr] + nums[rightPtr] != target))
        {
            if (nums[leftPtr] + nums[rightPtr] < target)
            {
                ++leftPtr;
            }
            else
            {
                --rightPtr;
            }
        }

        return std::vector<int>{leftPtr + 1, rightPtr + 1};
    }
};
