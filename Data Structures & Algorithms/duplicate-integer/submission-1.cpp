class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;

        for (const int num : nums){
            if(set.count(num)){
                return true;
            }
            set.insert(num);

        }
        return false;

    }
};