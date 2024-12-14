class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        int left = 0;
        long result = 0;
        int minidx = 0;
        int maxidx = 0;

        vector<int> min(nums.size());
        vector<int> max(nums.size());

        for (int right = 0; right < nums.size(); ++right) 
        {
            while (minidx > 0 && nums[min[minidx - 1]] >= nums[right]) 
            {
                minidx--;
            }
            while (maxidx > 0 && nums[max[maxidx - 1]] <= nums[right]) 
            {
                maxidx--;
            }

            min[minidx++] = right;
            max[maxidx++] = right;

            while (nums[max[0]] - nums[min[0]] > 2) 
            {
                left++;

                if (min[0] < left) 
                {
                    minidx--;

                    for (int i = 0; i < minidx; i++) 
                    {

                        min[i] = min[i + 1];
                    }
                }
                if (max[0] < left) 
                {
                    maxidx--;

                    for (int i = 0; i < maxidx; i++) 
                    {
                        max[i] = max[i + 1];
                    }
                }
            }
            result += (right - left + 1);
        }
        return result;
    }
};