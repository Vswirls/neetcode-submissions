// Heights are the integers within the array
// Area takes on the min of the two chosen integers
// Maximum area of the two bars -> essentially largest product
// If the larger "bar" decreases, we won't find a larger area
// Need to calculate with respects to the distance between

#include <vector>

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int output = min(heights[left], heights[right]) * (right - left);

        while (left < right) {
            int place_holder;

            if (min(heights[left], heights[right]) == heights[left]) {
                place_holder = heights[left] * (right - left);
                left++;     
            }
            else {
                place_holder = heights[right] * (right - left);
                right--;
            }
            
            output = max(output, place_holder);
        }

        return output;
    }
};
