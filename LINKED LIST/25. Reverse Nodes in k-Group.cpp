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
class Solution
{
public:
    // int getLength(ListNode* head) {
    //     int c = 0;
    //     while (head != NULL) {
    //         c++;
    //         head = head->next;
    //     }
    //     return c;
    // }
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if (head == NULL)
    //         return NULL;

    //     ListNode* next = NULL;
    //     ListNode* curr = head;
    //     ListNode* prev = NULL;
    //     int count = 0;
    //     while (curr != NULL and count < k) {
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //         count++;
    //     }
    //     if (next != NULL) {
    //         if (getLength(next) >= k) {

    //             head->next = reverseKGroup(next, k);
    //         } else {
    //             head->next = next;
    //         }
    //     }
    //     return prev;
    // }

    int getlength(ListNode *head)
    {
        int n = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            n++;
        }
        return n;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || getlength(head) < k)
            return head;
        ListNode *temp = NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;
        int cnt = 0;
        while (curr != NULL && cnt < k)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }
        if (temp != NULL)
            head->next = reverseKGroup(curr, k);
        return prev;
    }
};
