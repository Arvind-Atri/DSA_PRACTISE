#include <bits/stdc++.h> 
class CircularQueue{

    int*arr;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
         size=n;
        arr=new int[n];
         front=-1;
         rear=-1;

    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){

        // case 1:if queue is full
        if(front==0&&rear==size-1||rear==(front-1)%(size-1)){
            // cout<<"Queue is Full";
            return false;
        }
        
        // case 2:if queue is empty
        else if(rear==-1){
            front=0;
            rear=0;     //
            // rear=0;
            
            // arr[rear]=value;
        }
        //case 3:to maintain circular nature 
        else if((rear==size-1)&&front!=0){
            rear=0;
            // arr[rear]=value;
        }
        // case 4:
        else{
            rear++;
        }
        arr[rear]=value;
        return true;
        

    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        
        if(front==-1){
            // cout<<"queue is empty";
            return -1;    
        }
        
        int ans=arr[front];

        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }
};