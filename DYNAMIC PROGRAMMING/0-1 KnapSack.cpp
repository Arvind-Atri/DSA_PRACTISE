



#include <bits/stdc++.h> 


int solveRec(vector<int>weight,vector<int>value,int n,int W){

	if(W==0 || n==0) return 0;
	int include=0;
	if(weight[n-1]<=W){
		include=value[n-1]+solveRec(weight,value,n-1,W-weight[n-1]);
	}
	int exclude=solveRec(weight,value,n-1,W);

	return max(include,exclude);
}

int solveMem(vector<int>weight,vector<int>value,int n,int W,vector<vector<int>>&dp){

	if(W==0 || n==0) return 0;
	if(dp[n][W]!=-1) return dp[n][W];
	int include=0;
	if(weight[n-1]<=W){
		include=value[n-1]+solveMem(weight,value,n-1,W-weight[n-1],dp);
	}
	int exclude=solveMem(weight,value,n-1,W,dp);

	return dp[n][W]= max(include,exclude);
}
int solveTab(vector<int>weight,vector<int>value,int n,int W){
	vector<vector<int>>dp(n+1,vector<int>(W+1,0));
	for(int i=1;i<=n;i++){
		for(int w=0;w<=W;w++){
			int include=0;
			if(weight[i-1]<=w){
				include=value[i-1]+dp[i-1][w-weight[i-1]];
			}
			int exclude=dp[i-1][w];
			dp[i][w]=max(include,exclude);
		}
	}
	return dp[n][W];
}
int solveTabSO1(vector<int>weight,vector<int>value,int n,int W){
	// vector<vector<int>>dp(n+1,vector<int>(W+1,0));
	vector<int>prev(W+1,0);
	vector<int>curr(W+1,0);

	for(int i=1;i<=n;i++){
		for(int w=0;w<=W;w++){
			int include=0;
			if(weight[i-1]<=w){
				include=value[i-1]+prev[w-weight[i-1]];
			}
			int exclude=prev[w];
			curr[w]=max(include,exclude);
		}
		prev=curr;
	}
	return prev[W];
}
int solveTabSO2(vector<int>weight,vector<int>value,int n,int W){
	// vector<vector<int>>dp(n+1,vector<int>(W+1,0));
	// vector<int>prev(W+1,0);
	vector<int>curr(W+1,0);

	for(int i=1;i<=n;i++){
		for(int w=W;w>=0;w--){
			int include=0;
			if(weight[i-1]<=w){
				include=value[i-1]+curr[w-weight[i-1]];
			}
			int exclude=curr[w];
			curr[w]=max(include,exclude);
		}
		
	}
	return curr[W];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
	
	// return solveRec(weight,value,n,maxWeight);
	// vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,-1));
	// return solveMem(weight,value,n,maxWeight,dp);
    // return solveTab(weight, value, n, maxWeight);
       return solveTabSO2(weight, value, n, maxWeight);
}
