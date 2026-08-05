/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


// Method-1 
// TC-O(n)
// SC-O(n)
class Solution {
private:
    void insertAtTail(Node*&head,Node*&tail,int val){
            Node*temp=new Node(val);
            if(head==NULL){
                head=temp;
                tail=temp;
                return;
            }
            else{
                tail->next=temp;
                tail=temp;
            }
    }
public:
    Node* copyRandomList(Node* head) {
        // create clone linked list
        Node*cloneHead=NULL;
        Node*cloneTail=NULL;

        Node*temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
 
        // create mapping
        unordered_map<Node*,Node*>oldToNew;
        Node*cloneNode=cloneHead;
        Node*originalNode=head;
        while(originalNode!=NULL && cloneNode!=NULL){
                oldToNew[originalNode]=cloneNode;
                originalNode=originalNode->next;
                cloneNode=cloneNode->next;
                }
        originalNode=head;
        cloneNode=cloneHead;
    //   copy random pointers
        while(originalNode!=NULL  && cloneNode!=NULL){
            if(originalNode->random!=NULL){

            cloneNode->random=oldToNew[originalNode->random];
            }
            originalNode=originalNode->next;
                cloneNode=cloneNode->next;
        }
        return cloneHead;


    }
};





// Method-2
// TC-O(n)
// SC-O(1)
class Solution {
private:
    void insertAtTail(Node*&head,Node*&tail,int val){
            Node*temp=new Node(val);
            if(head==NULL){
                head=temp;
                tail=temp;
                return;
            }
            else{
                tail->next=temp;
                tail=temp;
            }
    }
public:
    Node* copyRandomList(Node* head) {
        // create clone linked list
        Node*cloneHead=NULL;
        Node*cloneTail=NULL;

        Node*temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
 
        // combine original and clone list
      
        Node*cloneNode=cloneHead;
        Node*originalNode=head;
        while(originalNode!=NULL && cloneNode!=NULL){
                Node*next=originalNode->next;
                originalNode->next=cloneNode;
                originalNode=next;

                next=cloneNode->next;
                cloneNode->next=originalNode;
                cloneNode=next;
                }
        temp=head;
    //   copy random pointers
        while(temp!=NULL){
            if(temp->next!=NULL){

            temp->next->random=temp->random?temp->random->next:temp->random;
            }
            temp=temp->next->next;
        }

        cloneNode=cloneHead;
        originalNode=head;
        while(originalNode!=NULL && cloneNode!=NULL){
                
                originalNode->next=cloneNode->next;
                originalNode=originalNode->next;

                if(originalNode!=NULL){

                cloneNode->next=originalNode->next;
                }
                cloneNode=cloneNode->next;
                }
        return cloneHead;


    }
};