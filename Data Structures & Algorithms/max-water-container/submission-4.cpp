class Solution {
public:
    int maxArea(vector<int>& heights) {
        int leftPtr = 0;
        int rightPtr = static_cast<int>(heights.size()) - 1;
        int maxArea{0};
        while ( leftPtr < rightPtr){
            int width = rightPtr - leftPtr;
            int height = std::min(heights[leftPtr], heights[rightPtr]);
            maxArea = std::max(maxArea, (width * height));

            if (heights[leftPtr] > heights[rightPtr]){
                --rightPtr;
            } else {
                ++leftPtr;
            }
        }

        return maxArea;
    }
};
