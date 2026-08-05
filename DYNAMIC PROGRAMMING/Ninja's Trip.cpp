


int solveMem(int n, vector<int>& days, vector<int>& cost,int index,vector<int>&dp){
    // Base Case
    if(index>=n) return 0;

    if(dp[index]!=-1) return dp[index];

    // 1 day pass
    int option1=cost[0]+solveMem(n,days, cost,index+1,dp);

    int i;
    // 7 days Pass
    //checking till where we can travel with 7 day pass (finding new index) if we just do index+7 it will go out of array and return  wrong ans
    // for example days = [1, 4, 6, 7, 8, 20] if we are standing at 4 i.e., index=1 if we do index+7 it give wrong ans ,we have to use the date to cal the next possible
    for(i=index;i<n && days[i]<days[index]+7;i++);   

    int option2=cost[1]+solveMem(n,days, cost, i,dp);

    // 30 days Pass
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solveMem(n,days, cost, i,dp);


    dp[index] =min(option1,min(option2,option3));
    return dp[index];
}


int solveTab(int n, vector<int>& days, vector<int>& cost){
    vector<int>dp(n+1,INT_MAX);

    dp[n]=0;
    for(int k=n-1;k>=0;k--){
            // 1 day pass
        int option1=cost[0]+dp[k+1];

        int i;
        // 7 days Pass
        //checking till where we can travel with 7 day pass (finding new index) if we just do index+7 it will go out of array and return  wrong ans
        // for example days = [1, 4, 6, 7, 8, 20] if we are standing at 4 i.e., index=1 if we do index+7 it give wrong ans ,we have to use the date to cal the next possible
        for(i=k;i<n && days[i]<days[k]+7;i++);   

        int option2=cost[1]+dp[i];

        // 30 days Pass
        for(i=k;i<n && days[i]<days[k]+30;i++);
        int option3=cost[2]+dp[i];


        dp[index] =min(option1,min(option2,option3));
    }
        return dp[0];
}




int minimumCoins(int n, vector<int> days, vector<int> cost)
{   vector<int>dp(n+1,-1);
    return solveMem(n,days, cost,0,dp);
}


days = [1, 4, 6, 7, 8, 20]


cost = [2, 7, 15]