
// When input is not reversed
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
private:
    Node *reverse(Node *&head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *nextNode = head;

        while (curr != NULL)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    void insertAtTail(Node *&head, Node *&tail, int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    struct Node *add(Node *num1, Node *num2)
    {
        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;

        while (num1 != NULL && num2 != NULL)
        {
            int sum = num1->data + num2->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(ansHead, ansTail, digit);
            num1 = num1->next;
            num2 = num2->next;
        }

        while (num1 != NULL)
        {
            int sum = num1->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(ansHead, ansTail, digit);
            num1 = num1->next;
        }
        while (num2 != NULL)
        {
            int sum = num2->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(ansHead, ansTail, digit);
            num2 = num2->next;
        }
        while (carry != 0)
        {
            int sum = carry;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, carry);
            carry = sum / 10;
        }
        return ansHead;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        num1 = reverse(num1);
        num2 = reverse(num2);

        Node *ans = add(num1, num2);

        ans = reverse(ans);
        while ((ans->data) == 0 && ans->next != NULL)
        {
            Node *temp = ans;
            delete (temp);
            ans = ans->next;
        }

        return ans;
    }
};

// When input list is already given as reversed

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        int total = 0, carry = 0;

        while (l1 || l2 || carry) {
            total = carry;

            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }

            int num = total % 10;
            carry = total / 10;
            dummy->next = new ListNode(num);
            dummy = dummy->next;
        }

        return res->next;        
    }
};