class Solution {


    // T.C-O((N-K)+NlogN)
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int,vector<int>,greater<int>>min_heap;
        
        for(int i=0;i<arr.size();i++){
            min_heap.push(arr[i]);
        }
        for(int i=0;i<k-1;i++){
            min_heap.pop();
        }
        return min_heap.top();
    }
};


// Method 2
// T.C- O(K + (N-K)LogK)

int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int>max_heap;
        
        for(int i=0;i<k;i++){
            max_heap.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(arr[i]<max_heap.top()){

            max_heap.pop();
            max_heap.push(arr[i]);
            }
        }
        return max_heap.top();
    }