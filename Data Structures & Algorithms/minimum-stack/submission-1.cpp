class MinStack {
private:
    std::stack<int> st;
    std::stack<int> minSt;

public:
    MinStack() = default;

    void push(int val)
    {
        st.push(val);

        if (minSt.empty() || val <= minSt.top())
        {
            minSt.push(val);
        }
    }

    void pop()
    {
        int topVal = st.top();
        if (minSt.top() == topVal)
        {
            minSt.pop();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};
