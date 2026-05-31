class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;

        // area[i] = min[prefixMax[i], suffixMax[i]] - height[i]
        int totalArea{0};

        // calculate prefix maxes by iterating from left to right; t: O(n), s: O(n)
        std::vector<int> prefixMaxArr;
        prefixMaxArr.reserve(height.size());
        int lastPrefixMax{height[0]};
        for (size_t i{0}; i < height.size(); ++i)
        {

            if (height[i] > lastPrefixMax)
            {
                lastPrefixMax = height[i];
            }
            prefixMaxArr.push_back(lastPrefixMax);
        }

        // calculate suffix maxes by iterating from right to left
        std::vector<int> suffixMaxArr(height.size(), 0);
        int lastSuffixMax{height[height.size() - 1]};
        for (int i = static_cast<int>(height.size()) - 1; i >= 0; --i)
        {

            if (height[i] > lastSuffixMax)
            {
                lastSuffixMax = height[i];
            }
            suffixMaxArr[i] = lastSuffixMax;
        }

        for (size_t i{0}; i < height.size(); ++i)
        {
            int area = std::min(suffixMaxArr[i], prefixMaxArr[i]) - height[i];
            totalArea += area;
        }

        return totalArea;
    }
};
