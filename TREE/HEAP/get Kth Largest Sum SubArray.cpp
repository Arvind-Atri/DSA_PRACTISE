#include<algorithm>
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{	 //APPROACH 1 

	// vector<int>ans;
	// for(int i=0;i<arr.size();i++){
	// 	int sum=0;
	// 	for(int j=i;j<arr.size();j++){
	// 		sum+=arr[j];
	// 		ans.push_back(sum);
	// 	}
	// }
	// sort(ans.begin(),ans.end());
	// return ans[ans.size()-k];


	// APPROACH 2 T.C OPTIMISED
	priority_queue<int,vector<int>,greater<int>>mini;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(mini.size()<k){
				mini.push(sum);
			}
			else{
				if(sum>mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}
