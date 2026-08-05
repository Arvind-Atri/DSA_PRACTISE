#include<iostream>
using namespace std;


class Queue{
public:
// properties

int *arr;
int qfront;
int qrear;
int size;


Queue(int size){
    qfront=qrear=0;
    arr=new int [size];
    
}

// behaviour

void enqueue(int val){
    if(isFull()){
        cout<<"QUEUE is FULL";
        return;
    }
    else{
        arr[qrear]=val;
        qrear++;
    }
}

int dequeue(){
    if(isEmpty()){
        cout<<"QUEUE is Empty";
        return -1;
    }
    else{
        int val=arr[qfront];
        arr[qfront]=-1;
        qfront++;
        if(qfront==qrear){
            qfront=0;
            qrear=0;
        }
        return val;

    }

}

int front(){
    if(isEmpty()){
        return -1;
    }
    else{
        return arr[qfront];
    }
}

int rear(){
    if(isEmpty()){
        return -1;
    }
    return arr[qrear-1];
}

bool isEmpty(){
    if(qfront==qrear){
        return true;
    }
    return false;
}

bool isFull(){
    if(qfront==size){
        return true;
    }
    return false;
}


};



int main(){

    Queue *q1=new Queue(10);

    q1->enqueue(1);
    q1->enqueue(2);

    cout<<q1->front()<<endl;
    cout<<q1->rear()<<endl;


}