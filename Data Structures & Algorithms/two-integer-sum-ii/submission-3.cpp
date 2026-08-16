// One valid solution
// One indexed
// Sorted in non-decreasing order -> lower index = smaller number
// When receiving a number -> ignore every number above it's index
// Scan left point and right pointer -> if left + right greater than sum, right goes left by one
// else, left goes right by one

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> output;
        int left = 0;
        int right = numbers.size() - 1;

        while (true) {
            if (numbers[right] + numbers[left] > target) {
                right -= 1;
            } else if (numbers[right] + numbers[left] < target) {
                left += 1;
            } else {
                output.push_back(left + 1);
                output.push_back(right + 1);
                return(output);
            }
        }
    }
};
