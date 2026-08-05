/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // Method 1
        // ListNode*temp=head;
        // map<ListNode*,bool>visited;

        // if(head==NULL||head->next==NULL){
        //     return false;
        // }

        // while(temp!=NULL){
        //     if(visited[temp]){
        //         return true;
        //     }
        //     visited[temp]=true;
        //     temp=temp->next;
        // }
        // return false;

        // Method 2

        if(head==NULL||head->next==NULL){
            return false;
        }

        ListNode*slow=head;
        ListNode*fast=head;

        while(slow!=NULL &&fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }

            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};