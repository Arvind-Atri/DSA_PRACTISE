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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        int l = 0, r = v.size() - 1;
        while (l < r && v[l] == v[r]) {
            l++;
            r--;
        }
        return l >= r;
    }
};



// Approach 2

class Solution
{
private:
    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *forward = NULL;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head->next == NULL)
        {
            return true;
        }
        ListNode *middle = getMid(head);
        cout << "midddlr" << middle->val << endl;
        ListNode *temp = middle->next;
        cout << "temp" << temp->val << endl;

        middle->next = reverse(temp);

        // compare both halves

        ListNode *head1 = head;
        ListNode *head2 = middle->next;
        while (head2 != NULL)
        {
            cout << "j" << head2->val;
            if (head1->val != head2->val)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        temp = middle->next;

        middle->next = reverse(temp);
        return true;
    }
};