class Solution {
public:
    #define ll long long
    void getSubtree(int node, vector<vector<int>>& adj, int par, vector<ll>& subtree){
        if(adj[node].size() == 1 && adj[node][0] == par){
            return;
        }
        for(auto it: adj[node]){
            if(it!=par){
                getSubtree(it, adj, node, subtree);
                subtree[node]+=subtree[it];
            }
        }
    }
    int cnt = 0;
    void dfs(int node, vector<vector<int>>& adj, int par, vector<ll>& subtree, int k){
        if(adj[node].size() == 1 && adj[node][0] == par){
            return;
        }
        for(auto it: adj[node]){
            if(it!=par){
                ll parSubtree = subtree[node] - subtree[it];
                ll childSubtree = subtree[it];
                if(parSubtree%k == 0 && childSubtree%k == 0){
                    cnt++;
                    subtree[node]-=subtree[it];
                }
                else subtree[it] = subtree[node];
                dfs(it, adj, node, subtree, k);
            }
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n+1);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<ll> subtree;
        for(auto it: values){
            subtree.push_back(it*1LL);
        }
        getSubtree(0, adj, -1, subtree);
        for(auto it: subtree) cout<< it <<" ";
        dfs(0, adj, -1, subtree, k);
        return cnt+1;
    }
};