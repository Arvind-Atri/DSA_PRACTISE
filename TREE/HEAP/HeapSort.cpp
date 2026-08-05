#include<iostream>
#include<queue>
using namespace std;

// T.c O(NlogN)
// can also be build using priority_queue
void heapify(int arr[],int n,int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if(left<=n&&arr[left]>arr[largest]){
            largest=left;
        }
        if(right<=n&&arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){ 
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}
  
int main(){
    int arr[10]={-1,54,53,55,52,50};
    for(int i=5/2;i>0;i--){
        heapify(arr,5,i);
    }
    heapsort(arr,5);

    for(int i=1;i<=5;i++){
        cout<<arr[i]<<" ";
    }



    cout<<"HEAPPP"<<endl;


    priority_queue<int>pq;

    pq.push(1);
    pq.push(3);
    pq.push(8);
    pq.push(4);
    pq.push(5);


    cout<<pq.top();



    priority_queue<int,vector<int>,greater<int>>mh;
    mh.push(9);
    mh.push(1);
    mh.push(6);
    mh.push(2);

    cout<<mh.top();
    mh.pop();
    cout<<mh.top();

}