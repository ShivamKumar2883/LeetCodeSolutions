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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int len = 0;
        ListNode* temp = head;

        while(temp) {
            len++;
            temp = temp->next;
        }

        int partSize = len / k;
        int extra = len % k;

        vector<ListNode*> ans(k, nullptr);

        temp = head;

        for(int i = 0; i < k && temp; i++) {
            ans[i] = temp;

            int size = partSize + ((extra > 0) ? 1 : 0);

            for(int j = 0; j < size-1; j++) {
                if(temp) {
                    temp = temp->next;
                }
            }

            if(temp) {
                ListNode* nextPart = temp->next;
                temp->next = nullptr;
                temp = nextPart;
            }

            extra--;
        }

        return ans;
    }
};