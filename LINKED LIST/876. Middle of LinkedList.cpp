//----method1----


int getLength(Node*head){
    Node*temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

Node *findMiddle(Node *head) {
    Node *temp=head;
    int ans=getLength(head)/2;
    int cnt=0;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;
}

//----Method 2----

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        { // for 0 or 1 node
            return head;
        }
        if (head->next->next == NULL)
        { // for 2 node
            return head->next;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};