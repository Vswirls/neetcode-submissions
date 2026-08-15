#include <vector>
#include <unordered_map>

// hash map that adds new key if num in nums does not exist as a key already
// +1 to value if key is there already
// Create buckets for all possible freqs -> nums.size + 1
// For-loop start at highest bucket, and add from highest bucket until results.size() == k

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto const& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        vector<int> result;

        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
            }

            if (result.size() >= k) {
                return result;
            }
        }

        return result;
    }
};
