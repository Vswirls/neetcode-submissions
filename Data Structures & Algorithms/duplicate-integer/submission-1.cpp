#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int i : nums) {
            if (seen.contains(i)) {
                return true;
            }
            seen.insert(i);
        }
        return false;
    }
};