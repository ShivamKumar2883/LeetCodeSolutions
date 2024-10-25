class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        sort(f.begin(),f.end());
        int i = 0, n =f.size();
        vector<string>ans;
        while(i<n){
            string cur  = f[i];
            int j = i+1,sz = cur.size();
            // cout<<cur<<endl;
            while(j<n && f[j].size()>sz  && cur == f[j].substr(0,sz) && f[j][sz]=='/'){
                // cout<<f[j]<<' '<<f[j].substr(0,sz);
                j++;
            }
            // cout<<endl;
            ans.push_back(f[i]);
            i=j;
        }
        return ans;
    }
};