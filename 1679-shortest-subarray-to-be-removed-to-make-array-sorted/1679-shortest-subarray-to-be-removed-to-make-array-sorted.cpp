class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), j=n-1;
        while(j > 0 && arr[j] >= arr[j-1]){
            j--;
        }

        int ans = j, i = 0;
        while(i < j && (i == 0 || arr[i-1] <= arr[i])){
            while(j < n && arr[i] > arr[j]){
                j++;
            }
            ans = min(ans, j-i-1);
            i++;
        }
        return ans;
    }
};