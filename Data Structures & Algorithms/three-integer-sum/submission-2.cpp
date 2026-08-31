// If a = -b - c, then three some is valid
// Sort so two pointer can be used
// Iterate through i and two pointer for each one

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.size() - 1;



            while (left < right) {
                if (nums[left] + nums[right] < -nums[i]) {
                    left++;
                } else if (nums[left] + nums[right] > -nums[i]) {
                    right--;
                } else {
                    vector<int> valid;
                    valid.insert(valid.begin(), {nums[left], nums[right], nums[i]});
                    output.push_back(valid);
                    left++;
                    right--;
                }
            }
        }

        return output;
    }
};
