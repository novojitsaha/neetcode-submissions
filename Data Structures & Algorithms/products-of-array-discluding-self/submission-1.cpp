class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // nums = {1,2,4,6}
        if (nums.size() == 2)
            return std::vector<int>{nums[1], nums[0]};

        std::vector<int> result(nums.size());

        // prefix pass
        result[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            result[i] = nums[i - 1] * result[i - 1];
        }

        // suffix pass
        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result[i] = result[i] * suffix;
            suffix *= nums[i];
        }

        return result;

    }
};
