/*


---Insertion----




---Deletion---
->Takes Place in Root Node
->Tree is heap

*/
#include<iostream>
using namespace std;


class Heap{
    public:
    int arr[100];
    int size;

    Heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;

        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void Delete(){
        if(size==0){
            cout<<"Nothing to Delete"<<endl;
            return;
        }
        // swap  last element with root node
        arr[1]=arr[size];
        size--;
        // take root node to its correct pos
        int i=1;
        while(i<size){
            int left=2*i;
            int right=2*i+1;

            if(left<=size&&right<=size){
                    
             
                if(arr[i]<arr[left]&&arr[right]<arr[left]){
               
                swap(arr[i],arr[left]);
                i=left;
                
                 }
                else if(arr[i]<arr[right]&&arr[left]<arr[right]){
              
                
                swap(arr[i],arr[right]);
                i=right;
               
                }
            }
            else{
                return;
            }
        }
    }
};





int main(){
    Heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    

    h.print();
    

    int arr[6]={-1,54,55,53,57,50};
    int n=5;
    for(int i=n/2;i>0;i--){ 
        cout<<"CALL"<<i<<endl;
        heapify(arr,n,i);
    }
    cout<<"Printing the Array Now"<<endl;

    for(int i=1; i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}