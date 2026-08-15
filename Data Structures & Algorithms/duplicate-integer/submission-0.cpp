#include <vector>
#include <unordered_set>

using namespace std; //bad practice - just makes it more efficient for this problem

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) { //reference used to save memory
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;
            }

            seen.insert(num);
        }
        
        return false;
    }
};