class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        set<int> s;
        map<int,vector<int>> st,en;
        for(int i=0;i<events.size();i++)
        {
            s.insert(events[i][0]);
            s.insert(events[i][1]);
            st[events[i][0]].push_back(events[i][2]);
            en[events[i][1]].push_back(events[i][2]);
        }
        int ended=0,ans=0;
        auto it=s.begin();
        while(it!=s.end())
        {
            int a=*it;
            for(int i=0;i<st[a].size();i++)
            {
                ans=max(ans,ended+st[a][i]);
            }
            for(int i=0;i<en[a].size();i++)
            {
                ended=max(ended,en[a][i]);
            }
            it++;
        }
        return ans;
    }
};