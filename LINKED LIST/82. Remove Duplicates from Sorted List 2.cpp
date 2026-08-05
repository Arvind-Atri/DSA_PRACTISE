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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* st = temp;
            while (temp->next != NULL && temp->next->val == temp->val) {
                temp = temp->next;
            }
            if (prev == NULL) {
                if (st == temp) {
                    prev = st;
                } else {
                    head = temp->next;
                }
            } else if (st == temp) {
                prev = st;
                // temp=temp->next;
            } else {
                prev->next = temp->next;
            }
            temp = temp->next;
        }
        return head;
    }
};