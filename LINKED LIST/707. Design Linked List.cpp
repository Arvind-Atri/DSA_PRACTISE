#include<iostream>
using namespace std;


class Node{
    public:
    int val;
    Node*next;

    Node(int data){
        this->val=data;
        this->next=NULL;
    }
};

class MyLinkedList {
public:
    Node*head;
    Node*tail;

    MyLinkedList() {
        head=NULL;
        tail=NULL;
    }
    
    int get(int index) {
        if (head == NULL) return -1;
        int i=0;
        Node*temp=head;
        while(i<=index-1 && temp!=NULL){
            temp=temp->next;
            i++;
        }
        if (temp == NULL) return -1;
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node*temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            temp->next=head;
            head=temp;
            return;
        }
    }
    
    void addAtTail(int val) {
        Node*temp=new Node(val);
        if(tail==NULL){
            tail=temp;
            head=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
            return;
        }
    }
    
    void addAtIndex(int index, int val) {
        Node*p=head;
        if(index==0){
            addAtHead(val);
            return;
        }
        int cnt=0;
        while(cnt!=index-1 && p!=NULL){
            cnt++;
            p=p->next;
        }
        if (p == NULL) return;
        if(p->next==NULL){
            addAtTail(val);
            return;
        }
        
        Node*temp=new Node(val);
        temp->next=p->next;
        p->next=temp;

    }
    
    void deleteAtIndex(int index) {
       
        Node*temp=head;
        if(head==NULL)return;
        else if(index==0){
            head=head->next;
            delete temp;
        }
        else{
            int cnt=0;

            while(cnt!=index-1){
                cnt++;
                temp=temp->next;

            }
            if (temp == NULL || temp->next == NULL) return;
            if(temp->next->next==NULL){
                tail=temp;
            }
            Node*del=temp->next;
            temp->next=temp->next->next;
            delete del;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){


MyLinkedList *obj=new MyLinkedList();
obj->addAtHead(1);
obj->print();
cout<<"HEAD-"<<obj->head->val<<" "<<"TAIL-"<<obj->tail->val<<endl;




obj->addAtTail(3);
obj->print();
cout<<"HEAD-"<<obj->head->val<<" "<<"TAIL-"<<obj->tail->val<<endl;



obj->addAtIndex(1,2);
obj->print();
cout<<"HEAD-"<<obj->head->val<<" "<<"TAIL-"<<obj->tail->val<<endl;


cout<<obj->get(1)<<endl;

obj->deleteAtIndex(1);
obj->print();
cout<<"HEAD-"<<obj->head->val<<" "<<"TAIL-"<<obj->tail->val<<endl;

cout<<obj->get(1)<<endl;

cout<<obj->get(3)<<endl;

obj->deleteAtIndex(3);
obj->print();
cout<<"HEAD-"<<obj->head->val<<" "<<"TAIL-"<<obj->tail->val<<endl;

obj->deleteAtIndex(0);
obj->print();
cout<<"HEAD-"<<obj->head->val<<" "<<"TAIL-"<<obj->tail->val<<endl;

cout<<obj->get(0)<<endl;

obj->deleteAtIndex(0);
obj->print();
cout<<"HEAD-"<<obj->head->val<<" "<<"TAIL-"<<obj->tail->val<<endl;

cout<<obj->get(0)<<endl;





j->head->val<<" "<<"TAIL-"<<obj->tail->val<<endl;


obj->addAtTail(4);
obj->print();
cout<<"HEAD-"<<obj->head->val<<" "<<"TAIL-"<<obj->tail->val<<endl;


// cout<<"GET"<<obj->get(1)<<endl;
// obj->deleteAtIndex(1);
// obj->print();
// cout<<"GET"<<obj->get(1)<<endl;



}