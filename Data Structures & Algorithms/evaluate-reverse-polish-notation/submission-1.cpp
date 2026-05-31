#include <stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;

        for (const std::string &s : tokens)
        {
            if (s == "+")
            {
                int top = stack.top();
                stack.pop();
                int bottom = stack.top();
                stack.pop();
                int operand = top + bottom;
                stack.emplace(operand);
            }
            else if (s == "-")
            {
                int top = stack.top();
                stack.pop();
                int bottom = stack.top();
                stack.pop();
                int operand = bottom - top;
                stack.emplace(operand);
            }
            else if (s == "*")
            {
                int top = stack.top();
                stack.pop();
                int bottom = stack.top();
                stack.pop();
                int operand = top * bottom;
                stack.emplace(operand);
            }
            else if (s == "/")
            {
                int top = stack.top();
                stack.pop();
                int bottom = stack.top();
                stack.pop();
                int operand = bottom / top;
                stack.emplace(operand);
            }
            else
            {
                int val = std::stoi(s);
                stack.emplace(val);
            }
        }
        return stack.top();
    }
};
