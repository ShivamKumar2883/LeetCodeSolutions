/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    int mp[100001]={0};

    int dfs(TreeNode* curr,int level,vector<vector<pair<int,int>>>&vec)
    {
        if(!curr)
            return -1;

        //later using this mp you can find the level of any node in O(1)
        mp[curr->val]=level;

        int l=1+dfs(curr->left,level+1,vec);
        int r=1+dfs(curr->right,level+1,vec);
        int h=max(l,r);

        //store  the highest and second highest depth of each level in vec
        if(vec[level][0].second<=h)
        {
            auto pr=vec[level][0];
            vec[level][0]={curr->val,h};
            vec[level][1]=pr;
        }
        else if(vec[level][1].second<=h)
        {
            vec[level][1]={curr->val,h};
        }
        
        //maximum depth of a node is maximum of its left and right child
        return max(l,r);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n=100001;
        
        memset(mp,-1,sizeof(mp));

        vector<vector<pair<int,int>>>vec(n,vector<pair<int,int>>(2,{0,0}));

        //mxht means Maximum height
        int mxht=dfs(root,0,vec);

        vector<int>ans;

        for(auto nd:queries)
        {
            auto &v=vec[mp[nd]];

            int x=mxht;
            
            //(v[0].first==nd) means => If the node i am deleting has the highest depth in this level. 
            //Then the new max height of the tree will be the  level i am standing at (mp[v[1].first]) + second highest depth in that level (v[1].second)


            // if(v[0].first != nd) means => If the node i am deleting is not the node with highest depth in the level then the height will not change at all.


            // (v[1].first==0) means=> If the level has only one node then the new height will be maximum height - the level of the node where i am standing now

            if(v[0].first==nd)
            {
                x=(v[1].first==0)?(mp[v[0].first]-1):mp[v[1].first]+v[1].second;
            }
            ans.push_back(x);    
        }

        return ans;
    }
};