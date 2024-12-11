class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=0,ans=0;
        while(r<nums.size()){
            if(nums[r]-nums[l]<=2*k) {
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};