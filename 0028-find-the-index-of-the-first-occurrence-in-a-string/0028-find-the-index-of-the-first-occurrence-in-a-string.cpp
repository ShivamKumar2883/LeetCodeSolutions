class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        std::vector<int> pi = computePrefixFunction(needle);
        int j = 0;
        for (int i = 0; i < haystack.length(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.length()) {
                return i - needle.length() + 1;
            }
        }
        return -1;
    }

private:
    std::vector<int> computePrefixFunction(const std::string& needle) {
        int N = needle.length();
        std::vector<int> pi(N);
        pi[0] = 0;
        for (int i = 1; i < N; i++) {
            int j = pi[i - 1];
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }
};