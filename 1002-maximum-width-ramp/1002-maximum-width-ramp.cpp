class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = std::max(rightMax[i + 1], nums[i]);

        int left = 0, right = 0, maxVal = 0;
        while (right < n) {
            while (right < n && nums[left] <= rightMax[right])
                right++;
            
            maxVal = std::max(maxVal, right - left - 1);
            left++;
            right = left + maxVal + 1; 
        }
        return maxVal;
    }
};