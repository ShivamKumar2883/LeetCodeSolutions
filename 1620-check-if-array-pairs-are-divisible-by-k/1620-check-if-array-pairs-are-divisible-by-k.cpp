class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for(auto& num : arr)
        {
            int remainder = ((num % k) + k) % k;
            freq[remainder]++;
        }
        //Check if pairs can be formed
        for(int i = 1; i < k; i++)
        {
            if(freq[i] != freq[k - i])
            {
                return false;
            }
        }
        //Handle special cases for remainder 0
        if(freq[0] % 2 != 0)
        {
            return false;
        }
        return true;
    }
};