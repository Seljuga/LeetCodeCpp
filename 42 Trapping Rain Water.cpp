class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0;
        int lMax = height[left], rMax = height[right];
        while (left < right) {
            if(height[left] <= height[right]) {
                if(height[left]<lMax) ans += lMax - height[left];
                else lMax = height[left];
                left++;
            }
            else {
                if(height[right]<rMax) ans += rMax - height[right];
                else rMax = height[right];
                right--;
            }
        }
        return ans;
    }
};
