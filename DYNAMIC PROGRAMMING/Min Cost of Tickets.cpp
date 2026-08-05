




int solve(int n, vector<int>& days, vector<int>& cost,int index){
    // Base Case
    if(index>=n) return 0;

    // 1 day pass
    int option1=cost[0]+solve(n,days, cost,index+1);

    int i;
    // 7 days Pass
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int option2=cost[1]+solve(n,days, cost, i);

    // 30 days Pass
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solve(n,days, cost, i);


    return min(option1,min(option2,option3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n,days, cost,0);
}

// Memoisation




int solveMem(int n, vector<int>& days, vector<int>& cost,int index,vector<int>&dp){
    // Base Case
    if(index>=n) return 0;

    if(dp[index]!=-1) return dp[index];

    // 1 day pass
    int option1=cost[0]+solveMem(n,days, cost,index+1,dp);

    int i;
    // 7 days Pass
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int option2=cost[1]+solveMem(n,days, cost, i,dp);

    // 30 days Pass
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solveMem(n,days, cost, i,dp);


    dp[index] =min(option1,min(option2,option3));
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{   vector<int>dp(n+1,-1);
    return solveMem(n,days, cost,0,dp);
}






// Dry Run:
// 2 Solutions Possible:  Days [ 1, 3, 4, 5, 7, 8, 20];  Costs[ 2, 7, 15]


// Solution 1:
// {
//  index  =   0  1  2  3  4  5  6
//  Costs =   1  3  4  5  7  8  20

// At index 0 Take Option1 -----> Cost[0] + At Index 1 Take Option2 ----> Cost[1] + Now we are at Index 6 Take Option1 ------> Cost[0] 
// Illustrated Below: ->
//  Days[0] ------------Option1------> 2 + Days[1] ------Option2------>7 + Days[6]---------Option1------>2

//  Days[0] <------Option1---------- 2  + 9          <------Option2---- 7 +  2         <---------Option1--------2

// Output : Days[0] = 11
// }

// Solution 2:
// {
// index  =   0  1  2  3  4  5  6
//  Costs =   1  3  4  5  7  8  20

// At index 0 Take Option2 -----> Cost[1] + Now we at Index 5 Take Option1 ----> Cost[0] + At index 6 Take Option1 ------> Cost[0] 
// Illustrated Below: ->
//  Days[0] ---------Option2 ---------> 7 + Days[5] ------Option1------>2 + Days[6]---------Option1------>2
//  Days[0] <------Option2  ---------- 7 + 4         <------Option1---- 2 +  2         <---------Option1--------2

// Output : Days[0] = 11

// }