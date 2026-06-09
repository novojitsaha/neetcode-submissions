#include <queue>
#include <functional>

class KthLargest {
   private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (const int num : nums) {
            minHeap.push(num);

            if (static_cast<int>(minHeap.size()) > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);

        if (static_cast<int>(minHeap.size()) > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
