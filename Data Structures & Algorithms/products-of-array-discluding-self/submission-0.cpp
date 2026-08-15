// Have an output array full of ones
// Starting from left to right, multiply and replace appropriate index
// Then multiply from right to left

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        vector<int> output(n, 1);

        for (int i = 0; i < n; i++) {
            output[i] *= prefix;
            prefix *= nums[i];
        }

        for (int j = nums.size() - 1; j >= 0; j--) {
            output[j] *= suffix;
            suffix *= nums[j];
        }

        return output;
    }
};
