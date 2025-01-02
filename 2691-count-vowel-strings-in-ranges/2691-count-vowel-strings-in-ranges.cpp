class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();

        // Step 1: Create a prefix sum array
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        // Step 2: Answer each query
        vector<int> result;
        for (const auto& query : queries) {
            int li = query[0], ri = query[1];
            result.push_back(prefixSum[ri + 1] - prefixSum[li]);
        }

        return result;
    }
};