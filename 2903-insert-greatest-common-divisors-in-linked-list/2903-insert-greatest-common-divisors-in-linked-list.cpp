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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* dummy1 = head;
        while (head->next != nullptr) {
            ListNode* newnode = head->next;
            ListNode* dummy = new ListNode(__gcd(head->val, head->next->val));
            head->next = dummy;
            dummy->next = newnode;
            head = newnode;
        }
        return dummy1;
    }
};