class Solution {
public:
    #define ll long long
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;

        // Step 1: Calculate prefix sum
        vector<ll> pref(n, 0);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i] + pref[i - 1];
        }

        // Step 2: Calculate total sum
        ll totalSum = pref[n - 1];

        // Step 3: Iterate through split points and check conditions
        for (int i = 0; i < n - 1; i++) {
            if (pref[i] >= (totalSum - pref[i])) {
                ans++;
            }
        }

        return ans;
    }
};