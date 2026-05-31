class Solution {
public:
    bool isPalindrome(string s) {
        const char *left = s.c_str();
        const char *right = s.c_str() + s.size() - 1;

        while (right > left)
        {
            while (right > left && !std::isalnum(*right))
            {
                --right;
            }

            while (right > left && !std::isalnum(*left))
            {
                ++left;
            }

            if (std::tolower(*right) != std::tolower(*left))
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
