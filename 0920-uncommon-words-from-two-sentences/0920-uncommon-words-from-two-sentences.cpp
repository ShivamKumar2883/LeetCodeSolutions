class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2){
        std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        unordered_map<string, int> mp;
        
        int len1 = s1.size();
        string curr1;
        for(int i=0; i<len1; i++){
            if(s1[i] == ' '){
                mp[curr1]++;
                curr1.clear();
            }
            else curr1 += s1[i];
        } 
        //add last word
        mp[curr1]++;

        int len2 = s2.size();
        string curr2;
        for(int i=0; i<len2; i++){
            if(s2[i] == ' '){
                mp[curr2]++;
                curr2.clear();
            }
            else curr2 += s2[i];
        } 
        //add last word
        mp[curr2]++;

        vector<string> res;
        for(auto& it: mp){
            if(it.second == 1) res.push_back(it.first);
        }
        return res;
    }
};