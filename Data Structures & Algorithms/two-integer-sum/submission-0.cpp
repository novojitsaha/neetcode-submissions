class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         std::unordered_map<int, int> hashMap;
         vector<int> v;

        for (int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(hashMap.count(complement)){
                int min = std::min(hashMap[complement], i);
                int max = std::max(hashMap[complement], i);
                return std::vector<int>{min, max};
            }
            hashMap[nums[i]] = i; 
        }

        return std::vector<int>{};
    }
};
