class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        // calculate total chalk needed for one cycle
        for (int i = 0; i < n; i++) {
            sum += chalk[i];
        }
        // reduce k modulo sum
        k = k % sum;
        // loop to find which student require chalk
        for (int i = 0; i < n; i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};