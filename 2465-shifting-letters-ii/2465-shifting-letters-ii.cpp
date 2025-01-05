class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>v(n+1);
        for(auto&shift:shifts){
            if(shift[2]){
                v[shift[0]]++;
                v[shift[1]+1]--;
            }
            else{
                v[shift[0]]--;
                v[shift[1]+1]++;
            }
        }
        for(int i=0;i<n;i++){
            v[i+1]+=v[i];

        }
        for(int i=0;i<n;i++){
            s[i]=((s[i]-'a')+(v[i]%26+26))%26+'a';
        }
        return s;
    }
};