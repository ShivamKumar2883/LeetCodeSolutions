class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int ele=grid[j][i];
                int c=i+1;
                int maxi=-1;
                int x=-1,y=-1;
                for(int k=-1;k<=1;k++)
                {
                    int r=j+k;
                    if(r>=0&&r<m&&j>=0&&grid[r][c]>ele)
                    {
                       if(vis[r][c]>maxi)
                       {
                           maxi=vis[r][c];
                           x=r;y=c;
                       }
                    }
                }
                if(x!=-1&&y!=-1&&maxi!=-1)
                vis[j][i]=1+vis[x][y];
                else
                vis[j][i]=0;

            }
        }
       int ans=0;
       for(int i=0;i<m;i++)
       ans=max(ans,vis[i][0]);
        return ans;
    }
};