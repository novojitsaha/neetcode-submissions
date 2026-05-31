class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // i'll use a monotonically decreasing stack
        std::stack<int> stack;
        std::vector<int> result(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            while(!stack.empty() && temperatures[i] >= temperatures[stack.top()]){
                stack.pop();
            }
            if (!stack.empty()){
                result[i] = stack.top() - i;
            }
            stack.push(i);
        }

        return result;
    }
};
