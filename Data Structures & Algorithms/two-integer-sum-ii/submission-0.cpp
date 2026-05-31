class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
                int *left = &numbers[0];
        int *right = &numbers[numbers.size() - 1];

        while (*left + *right != target)
        {
            if (*left + *right > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        int index1 = static_cast<int>(left - &numbers[0]) + 1;
        int index2 = static_cast<int>(right - &numbers[0]) + 1;
        return std::vector<int>{index1, index2};
    }
};
