
// Recursive Approach
void solve(ListNode*&head,ListNode*curr,ListNode*prev){
        if(curr==NULL){
            head=prev;
            return;
        }


        ListNode*forward=curr->next;
        solve(head,forward,curr);
        curr->next=prev;
        

    }


// Recursive Approach 2
Node* reverseList(Node*head){
    if(head==NULL ||head->next==NULL){
        return head;
    }

    Node* mainHead=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;

    return mainHead;
}

// ----Iterative Approach
 ListNode* reverseList(ListNode* head) {



        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*forward=NULL;

    

        if(head==NULL || head->next==NULL){
            return head;
        }




        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
        
    }