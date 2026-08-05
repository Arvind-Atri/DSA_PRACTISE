#include<iostream>
using namespace std;
int main(){

    // optimised approach
    int n=5;
    int arr[5]={1,2,3,4,5};
    int maxSum=INT64_MIN;
    for(int st=0;st<n;st++){
        int currSum=0;
        for(int end=st;end<n;end++){
            currSum+=arr[end];
            maxSum=max(currSum,maxSum);
        }
    }
    cout<<maxSum<<endl;



    // kadane's Algo

    int maxSum = INT64_MIN;
    int currSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}