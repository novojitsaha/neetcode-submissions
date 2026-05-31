class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> stack;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i)
        {
            int currentHeight = i == n ? 0 : heights[i];

            while (!stack.empty() && currentHeight < heights[stack.top()])
            {
                int poppedHeight = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                int area = poppedHeight * width;
                maxArea = std::max(area, maxArea);
            }

            stack.push(i);
        }
        return maxArea;
    }
};
