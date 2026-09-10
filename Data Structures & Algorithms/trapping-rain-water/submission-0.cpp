// Two pointers 
// Left pointer and Right pointer
// Max Left
// min(mLeft, mRight) - height[i] = water
// adjust mleft/mright as you go down the pointers

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int left = 0, right = height.size() - 1;
        int maxLeft = height[left], maxRight = height[right];
        int output = 0;

        while (left < right) {
            if (maxLeft < maxRight) {
                left += 1;
                maxLeft = max(maxLeft, height[left]);
                output += maxLeft - height[left];
            } else {
                right -= 1;
                maxRight = max(maxRight, height[right]);
                output += maxRight - height[right];
            }
        }
        // 0, 1 -> left = 1 -> maxLeft = 2, ou
        return output;
    }
};
