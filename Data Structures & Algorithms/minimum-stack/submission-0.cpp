class MinStack {
    private:
        std::vector<std::pair<int, int>> stack_;
public:
    MinStack() = default;

    // O(1) since vector insertion at the end is amortized O(1)
    void push(int val)
    {
        if (stack_.empty()){
            stack_.emplace_back(val, val);
        } else {
            val < stack_.back().second ? stack_.emplace_back(val, val) : stack_.emplace_back(val, stack_.back().second); 
        }
    }
    // O(1) since vector removal at the end is amortized O(1)
    void pop()
    {
        stack_.pop_back();
    }

    int top()
    {
        return stack_.back().first;
    }

    int getMin()
    {
        return stack_.back().second;
    }
};
