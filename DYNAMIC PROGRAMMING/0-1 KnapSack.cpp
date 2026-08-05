 #include <bits/stdc++.h> 


int solve(vector<int> weight, vector<int> value, int index, int W){
	if(index==0){
		if(weight[0]<=W) return value[0];
		else{
			return 0;
		}
	}
	int include=0;
	if(weight[index]<=W)
		include=value[index]+solve(weight, value, index-1, W-weight[index]);
	int exclude=0+solve(weight,value,index-1,W);
	return max(include,exclude);
}

int solveMem(vector<int> weight, vector<int> value, int index, int W,vector<vector<int>>&dp){
	if(index==0){
		if(weight[0]<=W) return value[index];
		else{
			return 0;
		}
	}
	if(dp[index][W]!=-1)return dp[index][W];
	int include=0;
	if(weight[index]<=W)
		include=value[index]+solveMem(weight, value, index-1, W-weight[index],dp);
	int exclude=0+solveMem(weight,value,index-1,W,dp);
	dp[index][W]= max(include,exclude);
	return dp[index][W];
}

int solveTab(vector<int> weight, vector<int> value, int index, int capacity)
{
	vector<vector<int>> dp(index, vector<int>(capacity + 1, 0));

	for (int w = weight[0]; w <= capacity; w++)
	{
		if (weight[0] <= capacity)
			dp[0][w] = value[0];
		else
			dp[0][w] = 0;
	}

	for (int i = 1; i < index; i++)
	{
		for (int w = 0; w <= capacity; w++)
		{
			int include = 0;
			if (weight[i] <= w)
			{
				include = dp[i - 1][w - weight[i]] + value[i];
			}
			int exclude = 0 + dp[i - 1][w];

			dp[i][w] = max(include, exclude);
		}
	}
	return dp[index - 1][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	// vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	// return solveRec(weight,value,n-1,maxWeight,dp);

	return solveTab(weight, value, n, maxWeight);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
		vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return solveMem(weight, value, n-1, maxWeight,dp);
}

int solveTab(vector<int> weight, vector<int> value, int index, int capacity)
{
	// vector<vector<int>>dp(index,vector<int>(capacity+1,0));

	vector<int> prev(capacity + 1, 0);
	vector<int> curr(capacity + 1, 0);
	for (int w = weight[0]; w <= capacity; w++)
	{
		if (weight[0] <= capacity)
			prev[w] = value[0];
		else
			prev[w] = 0;
	}

	for (int i = 1; i < index; i++)
	{
		for (int w = 0; w <= capacity; w++)
		{
			int include = 0;
			if (weight[i] <= w)
			{
				include = prev[w - weight[i]] + value[i];
			}
			int exclude = 0 + prev[w];

			curr[w] = max(include, exclude);
		}
		prev = curr;
	}
	return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	// vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	// return solveRec(weight,value,n-1,maxWeight,dp);

	return solveTab(weight, value, n, maxWeight);
}

int solveTab(vector<int> weight, vector<int> value, int index, int capacity)
{
	// vector<vector<int>>dp(index,vector<int>(capacity+1,0));

	// vector<int>prev(capacity+1,0);
	vector<int> curr(capacity + 1, 0);
	for (int w = weight[0]; w <= capacity; w++)
	{
		if (weight[0] <= capacity)
			curr[w] = value[0];
		else
			curr[w] = 0;
	}

	for (int i = 1; i < index; i++)
	{
		for (int w = capacity; w >= 0; w--)
		{
			int include = 0;
			if (weight[i] <= w)
			{
				include = curr[w - weight[i]] + value[i];
			}
			int exclude = 0 + curr[w];

			curr[w] = max(include, exclude);
		}
	}
	return curr[capacity];
}