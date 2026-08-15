// Hash-set: goes through once, if n-1 is in the array

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookups(nums.begin(), nums.end());
        int output = 0;

        for (int num : lookups) {
            if (!lookups.contains(num - 1)) {
                int i = 1;
                while (lookups.contains(num + i)) {
                    i++;
                }

                if (i > output) {
                    output = i;
                }
            }
        }

        return output;
    }
};
