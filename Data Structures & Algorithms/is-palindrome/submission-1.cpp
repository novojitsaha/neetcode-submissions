class Solution {
public:
    bool isPalindrome(string str) {
        int leftPtr = 0;
        int rightPtr = str.size() - 1;

        while (leftPtr < rightPtr)
        {
            while (!std::isalnum(static_cast<unsigned char>(str[leftPtr])) && leftPtr < rightPtr)
            {
                ++leftPtr;
            }

            while (!std::isalnum(static_cast<unsigned char>(str[rightPtr])) && leftPtr < rightPtr)
            {
                --rightPtr;
            }

            if (std::tolower(static_cast<unsigned char>(str[leftPtr])) != std::tolower(static_cast<unsigned char>(str[rightPtr])))
            {
                return false;
            }
            leftPtr++;
            rightPtr--;
        }

        return true;
    }
};
