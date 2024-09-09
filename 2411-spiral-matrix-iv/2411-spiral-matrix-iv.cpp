/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int top = 0, bottom = m-1, left = 0, right = n-1;

        while(top<=bottom && left<=right && head != NULL){
            for(int j = left; j<=right && head != NULL; j++){
                ans[top][j] = head->val;
                head = head->next;
            }
            top++;

            for(int i = top; i<=bottom && head != NULL; i++){
                ans[i][right] = head->val;
                head = head->next;
            }
            right--;

            for(int j = right; j>=left && head != NULL; j--){
                ans[bottom][j] = head->val;
                head = head->next;
            }
            bottom--;

            for(int i = bottom; i>=top && head != NULL; i--){
                ans[i][left] = head->val;
                head = head->next;
            }
            left++;
        }

        return ans;
    }
};