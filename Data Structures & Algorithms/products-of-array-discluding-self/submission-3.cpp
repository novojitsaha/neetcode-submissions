class Solution {
public:
    vector<int> productExceptSelf(vector<int>& inputArr) {
        std::vector<int> result(inputArr.size(), 1);

        int prefixProduct{1};
        for (size_t i{0}; i < inputArr.size(); ++i)
        {
            result[i] = prefixProduct;
            prefixProduct *= inputArr[i];
        }

        int suffixProduct{1};
        for (size_t i{inputArr.size()}; i-- > 0;)
        {
            result[i] *= suffixProduct;
            suffixProduct *= inputArr[i];
        }

        return result;

    }
};
