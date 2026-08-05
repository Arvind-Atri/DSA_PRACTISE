#include<limits.h>

int solve(int n,int x,int y,int z,vector<int>&dp){
	if(n==0) return 0;

	if(n<0) return INT_MIN;

	if(dp[n]!=-1)return dp[n];

	int a=solve(n-x, x, y, z,dp)+1;
	int b=solve(n-y, x, y, z,dp)+1;
	int c=solve(n-z, x, y, z,dp)+1;

	dp[n]= max(a,max(b,c));
	return dp[n];


}


int solveTab(int n,int x,int y,int z){
	vector<int>dp(n+1,INT_MIN);
	dp[0]=0;

	for(int i=1;i<=n;i++){
		if(i-x>=0)
			dp[i]=max(dp[i],dp[i-x]+1);
		if(i-y>=0)
			dp[i]=max(dp[i],dp[i-y]+1);
		if(i-z>=0)
			dp[i]=max(dp[i],dp[i-z]+1);
	}
	if(dp[n]<0) return 0;
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// vector<int>dp(n+1,-1);
	// int ans=solve(n, x, y, z,dp);
	int ans=solveTab(n, x, y, z);


	// if(ans<0) return 0;
	return ans;
}




// n = 7 (the rod length)
// x = 5, y = 2, z = 2 (the segment lengths)
// Initial Setup:
// dp = [0, -∞, -∞, -∞, -∞, -∞, -∞, -∞]
// (Initialized with INT_MIN to represent an impossible cut. dp[0] = 0 because cutting a rod of length 0 requires 0 segments.)
// Step 2: Loop through rod lengths (i = 1 to i = 7)
// We'll now calculate the maximum number of segments for each length of the rod by considering cuts of lengths x = 5, y = 2, and z = 2.

// For i = 1:

// We cannot cut a segment of length 5 (1 - 5 < 0), so skip.
// We cannot cut a segment of length 2 (1 - 2 < 0), so skip.
// No cuts are possible, so dp[1] remains -∞.
// Updated dp = [0, -∞, -∞, -∞, -∞, -∞, -∞, -∞].

// For i = 2:

// We cannot cut a segment of length 5 (2 - 5 < 0), so skip.
// We can cut a segment of length 2:
// dp[2] = max(dp[2], dp[2 - 2] + 1) = max(-∞, 0 + 1) = 1.
// No further cuts are possible.
// Updated dp = [0, -∞, 1, -∞, -∞, -∞, -∞, -∞].

// For i = 3:

// We cannot cut a segment of length 5 (3 - 5 < 0), so skip.
// We cannot cut a segment of length 2 (3 - 2 = 1 and dp[1] = -∞), so skip.
// No cuts are possible, so dp[3] remains -∞.
// Updated dp = [0, -∞, 1, -∞, -∞, -∞, -∞, -∞].

// For i = 4:

// We cannot cut a segment of length 5 (4 - 5 < 0), so skip.
// We can cut a segment of length 2:
// dp[4] = max(dp[4], dp[4 - 2] + 1) = max(-∞, 1 + 1) = 2.
// No further cuts are possible.
// Updated dp = [0, -∞, 1, -∞, 2, -∞, -∞, -∞].

// For i = 5:

// We can cut a segment of length 5:
// dp[5] = max(dp[5], dp[5 - 5] + 1) = max(-∞, 0 + 1) = 1.
// No further cuts are possible with length 2.
// Updated dp = [0, -∞, 1, -∞, 2, 1, -∞, -∞].

// For i = 6:

// We can cut a segment of length 5 (6 - 5 = 1 and dp[1] = -∞), so skip.
// We can cut a segment of length 2:
// dp[6] = max(dp[6], dp[6 - 2] + 1) = max(-∞, 2 + 1) = 3.
// No further cuts are possible.
// Updated dp = [0, -∞, 1, -∞, 2, 1, 3, -∞].

// For i = 7:

// We can cut a segment of length 5:
// dp[7] = max(dp[7], dp[7 - 5] + 1) = max(-∞, 1 + 1) = 2.
// We can cut a segment of length 2:
// dp[7] = max(dp[7], dp[7 - 2] + 1) = max(2, 1 + 1) = 2.
// No further cuts are possible.
// Updated dp = [0, -∞, 1, -∞, 2, 1, 3, 2]