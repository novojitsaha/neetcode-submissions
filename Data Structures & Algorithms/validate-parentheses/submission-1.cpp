#include <stack>
class Solution {
public:
    bool isValid(string s) {
std::stack<char> charStack;

        for (const char &c : s)
        {
            switch (c)
            {
            case '(':
                charStack.push(c);
                break;
            case ')':
                if (charStack.empty())
                    return false;
                if (charStack.top() == '(')
                {
                    charStack.pop();
                }
                else
                {
                    return false;
                }
                break;
            case '{':
                charStack.push(c);
                break;
            case '}':
                if (charStack.empty())
                    return false;
                if (charStack.top() == '{')
                {
                    charStack.pop();
                }
                else
                {
                    return false;
                }
                break;

            case '[':
                charStack.push(c);
                break;
            case ']':
                if (charStack.empty())
                    return false;
                if (charStack.top() == '[')
                {
                    charStack.pop();
                }
                else
                {
                    return false;
                }
                break;
            }
        }
        if (charStack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
