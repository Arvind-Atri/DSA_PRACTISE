
// T.c-O(n*klog(k))
// S.C-O(K)

#include<queue>
class compare{
    public:
    bool operator()(Node*a,Node*b){
        return a->data >b->data;
    }
};
Node* mergeKLists(vector<Node*> &listArray){
    int k=listArray.size();
    if(k==0) return NULL;
    priority_queue<Node*,vector<Node*>,compare>minHeap;
    for(int i=0;i<k;i++){
       
            minHeap.push(listArray[i]);
        
    }
    Node*head=NULL;
    Node*tail=NULL;
    
    while(minHeap.size()>0){
        Node*top=minHeap.top();
        minHeap.pop();

        if(top->next!=NULL){
                minHeap.push(top->next);
        }

        if(head==NULL){
            // LL is empty
            head=top;
            tail=top;
            
        }else{
            // insert at linked list
            tail->next=top;
            tail=top;
            
        }

        
    }
    return head;
}
