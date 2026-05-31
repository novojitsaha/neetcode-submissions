class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         // {element : frequency}
        std::unordered_map<int, int> freqMap;

        //  t: O(n), s: O(n)
        for (const int &i : nums)
        {
            freqMap[i]++;
        }

        // bucket sort by frequency: bucket n will contain elements with n frequency
        std::vector<std::vector<int>> bucket(nums.size() + 1);

        // t: O(n), s: O(n)
        for (auto &[elem, freq] : freqMap)
        {
            bucket[freq].push_back(elem);
        }

        std::vector<int> result;
        result.reserve(k);
        // collect top k elements from each bucket. t: O(n), s: O(1)
        for (int i = bucket.size() - 1; i > 0 && result.size() < k; i--)
        {
            for (const int &e : bucket[i])
            {
                result.push_back(e);
                if (result.size() == k)
                    break;
            }
        }
        return result;
    }
};
