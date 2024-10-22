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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> levelSum;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int currLevelSize = q.size();
            long long sum = 0;
            while(currLevelSize--){
                TreeNode* currNode = q.front();
                q.pop();


                sum+=currNode->val;

                if(currNode->left!=nullptr){
                    q.push(currNode->left);
                }

                if(currNode->right!=nullptr){
                    q.push(currNode->right);
                }

            }

            
            levelSum.push(sum);
            if(levelSum.size() > k) levelSum.pop();
        }

        if(levelSum.size()<k) return -1;

        return levelSum.top();
    }
};