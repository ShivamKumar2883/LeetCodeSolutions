class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0; i < k; ++i) {
            auto minIt = min_element(nums.begin(), nums.end());
            *minIt *= multiplier;
        }
        return nums;
    }
};