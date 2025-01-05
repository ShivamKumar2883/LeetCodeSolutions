class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, vector<int>> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int ans=0;
        for(auto it: mp){
            vector<int> ind = it.second;
            int st = ind[0];
            int e = ind[ind.size()-1];
            // cout<<it.first;
            // for(auto it: ind){
            //     cout<<it<<" ";
            // }
            if(e-st<=1){
                continue;
            }
            else{
                map<char, int> mpp;
                for(int i=st+1; i<e; i++){
                    mpp[s[i]]++;
                }
                ans+=mpp.size();
            }
        }
        return ans;
    }
};