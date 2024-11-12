class Solution {
public:
    int solve(vector<pair<int,int>>&v,int query){
        int s=0,e=v.size()-1;
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(v[mid].first<=query){
                ans=v[mid].second;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=queries.size();
        unordered_map<int,int>mp;
        for(auto item:items){
            if(mp.count(item[0])){
                if(item[1]>mp[item[0]]){
                    mp[item[0]]=item[1];
                }
            }
            else{
                mp[item[0]]=item[1];
            }
        }
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back(it);
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            v[i].second=max(v[i-1].second,v[i].second);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(solve(v,queries[i]));
        }
        return ans;
    }
};