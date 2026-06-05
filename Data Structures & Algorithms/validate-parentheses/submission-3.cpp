#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

        for (const char c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                st.push(c);
                break;

            case ')':
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
                break;

            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
                break;

            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
                break;
            }
        }
        return st.empty();

    }
};
