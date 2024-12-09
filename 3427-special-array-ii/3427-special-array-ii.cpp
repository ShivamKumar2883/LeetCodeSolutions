class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> v;
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) || (nums[i] % 2 != 0 && nums[i + 1] % 2 != 0)) {
                v.push_back(i);
            }
        }
        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            bool found = false;
            for (auto it : v) {
                if (it >= e) {
                    ans.push_back(true);
                    found = true;
                    break;
                }
                if (it < e && it >= s) {
                    ans.push_back(false);
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back(true);
            }
        }
        return ans;
    }
};