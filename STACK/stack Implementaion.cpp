#include<iostream>
using namespace std;


// Method 1-Implementation using Array

class Stack{
    public:
    // properties
    int top;
    int *arr;
    int size;   

    // behaviour
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element){
        if(!isFull()){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"STack Overflow";
        }
    }
    int pop(){
        if(!isEmpty()){
            int val=arr[top];
            top--;
            return val;
        }
        else{
            cout<<"Stack Underflow";
            return -1;
        }
    }
    int peek(){
        if(!isEmpty()){
        int val=arr[top];
        return val;
        }
        else{
            return -1;
        }
    }

    bool isFull(){
        if(top==size-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};


int main(){

    Stack*S1=new Stack(5);
    cout<<S1->peek() ;
    S1->push(1);
    cout<<S1->peek();
    S1->push(2);
    cout<<S1->peek();
    S1->push(3);
    cout<<S1->peek();

}




// Method 2-Implementation using Linked List