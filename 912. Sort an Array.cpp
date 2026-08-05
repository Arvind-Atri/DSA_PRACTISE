class Solution {
private:

    void merge(vector<int>&nums,int s,int e){
        int mid=(s+e)/2;
        
        int len1=mid-s+1;
        int len2=e-mid;

        int *arr1=new int[len1];
        int *arr2=new int[len2];

        int mainArrayIndex=s;
        for(int i=0;i<len1;i++){
            arr1[i]=nums[mainArrayIndex++];
        }
        mainArrayIndex=mid+1;
        for(int i=0;i<len2;i++){
            arr2[i]=nums[mainArrayIndex++];
        }

        int i=0;
        int j=0;
        mainArrayIndex=s;
        while(i<len1 && j<len2){
            if(arr1[i]<arr2[j]){
                nums[mainArrayIndex++]=arr1[i++];
            }
            else{
                nums[mainArrayIndex++]=arr2[j++];
            }
        }
        while(i<len1){
            nums[mainArrayIndex++]=arr1[i++];
        }
        while(i<len2){
            nums[mainArrayIndex++]=arr2[j++];
        }
    }

    void mergeSort(vector<int>&nums,int s,int e){
        int mid=s+(e-s)/2;
        if(s>=e){
            return;
        }

        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,e);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};