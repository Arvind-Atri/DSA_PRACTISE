#include<iostream>
using namespace std;
int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;}
            }
    // pivot is at its right place 
    int pivotindex=s+count;
    swap(arr[pivotindex],arr[s]);

    int i=s;
    int j=e;
    while(i<pivotindex&&j>pivotindex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        // if(i<pivotindex&&j>pivotindex){
            swap(arr[i],arr[j]);
        // }
    }
    return pivotindex;
     
}
void quick_sort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);

    // sorting left part 

    quick_sort(arr,s,p-1);

    // sorting right part
    quick_sort(arr,p+1,e);
}

int main(){

    int arr[]={5,3,7,2,9,1};
    int size=sizeof(arr)/sizeof(arr[0]);

    quick_sort(arr,0,size-1);
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
}