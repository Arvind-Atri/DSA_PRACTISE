// Recursion


class Solution {
private:
    int solve(string &a,string &b,int i,int j)
    {
        //Base case
        if(i==a.length())
        {
            return b.length()-j;
        }
        if(j==b.length())
        {
            return a.length()-i;
        }

        int ans=0;
        if(a[i]==b[j]) return solve(a,b,i+1,j+1);
        else
        {
            //insert
            int insertans=1+solve(a,b,i,j+1);

            //delete
            int deleteans=1+solve(a,b,i+1,j);

            //replace
            int replaceans=1+solve(a,b,i+1,j+1);

            ans=min(insertans,min(deleteans,replaceans));
        }
        return ans;
    }    
public:
    int minDistance(string word1, string word2) {
         return solve(word1,word2,0,0);
    }
};


// Approach 2: Memoization

class Solution {
private:
    int solveMem(string &a,string &b,int i,int j,vector<vector<int>> &dp)
    {
        //Base case
        if(i==a.length())
        {
            return b.length()-j;
        }
        if(j==b.length())
        {
            return a.length()-i;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        if(a[i]==b[j]) return solveMem(a,b,i+1,j+1,dp);
        else
        {
            //insert
            int insertans=1+solveMem(a,b,i,j+1,dp);

            //delete
            int deleteans=1+solveMem(a,b,i+1,j,dp);

            //replace
            int replaceans=1+solveMem(a,b,i+1,j+1,dp);

            ans=min(insertans,min(deleteans,replaceans));
        }
        return dp[i][j]=ans;
    }      

public:
    int minDistance(string word1, string word2) {

         int n=word1.length();
         int m=word2.length();

         vector<vector<int>> dp(n,vector<int> (m,-1));
         return solveMem(word1,word2,0,0,dp);
    }
};



// Approach 3: Tabulation


class Solution {
private:
    int solveTab(string &a,string &b)
    {
        int n=a.length();
        int m=b.length();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int j=0;j<m;j++)
        {
            dp[n][j]=m-j;
        }

        for(int i=0;i<n;i++)
        {
            dp[i][m]=n-i;
        }   

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                    int ans=0;
                    if(a[i]==b[j]) ans= dp[i+1][j+1];
                    else
                    {
                        //insert
                        int insertans=1+dp[i][j+1];

                        //delete
                        int deleteans=1+dp[i+1][j];

                        //replace
                        int replaceans=1+dp[i+1][j+1];

                         ans=min(insertans,min(deleteans,replaceans));
                    }
                     dp[i][j]=ans;
            }
        }
        return dp[0][0];   
    }  

public:
    int minDistance(string word1, string word2) {
 
         return solveTab(word1,word2);
    }
};



// Approach 4: Space Optimization



class Solution {
private:
    int solveSO(string &a,string &b)
    {
        int n=a.length();
        int m=b.length();

        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
//TODO
        for(int j=0;j<m;j++)
        {
            next[j]=m-j;
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                //catch here ->base case se nikal ke laye
                curr[m]=n-i;
                    int ans=0;
                    if(a[i]==b[j]) ans= next[j+1];
                    else
                    {
                        //insert
                        int insertans=1+curr[j+1];

                        //delete
                        int deleteans=1+next[j];

                        //replace
                        int replaceans=1+next[j+1];

                         ans=min(insertans,min(deleteans,replaceans));
                    }
                     curr[j]=ans;
            }
            next=curr;
        }
        return next[0];   
    }    
public:
    int minDistance(string word1, string word2) {
    
        if(word1.length()==0) return word2.length();
        if(word2.length()==0) return word1.length();
        return solveSO(word1,word2);
    }
};