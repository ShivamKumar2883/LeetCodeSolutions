class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> vect;
        for(int i=1; i<=n; ++i) vect.push_back(i);
        sort(vect.begin(), vect.end(), [](int left, int right){
            return to_string(left)<to_string(right);
        });
        return vect;
    }
};