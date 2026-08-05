















in this sapce complexity can be reduced by using integer insteadof visited arr



// Using Recursion And BackTracking

#include <bits/stdc++.h> 

bool issafe(int newx,int newy,vector<vector<bool>>&visited,vector < vector < int >> & arr,int n){
    if((newx>=0&&newx<n)&&(newy>=0&&newy<n)&&(visited[newx][newy]==0)&&(arr[newx][newy]==1)){
        return true;
    }
    else{
        return false;
    }
}
void solve(int x,int y,vector < vector < int >> & arr,int n,vector<string>&ans,vector<vector<bool>>&visited,string path){
    if(x==n-1&&y==n-1){
        ans.push_back(path);
        return;
    }

    // 4 movements
    // D L R U

    // down
    if(issafe(x+1,y,visited,arr,n)){
        visited[x][y]=1;
        solve(x+1,y,arr,n,ans,visited,path+'D');
        visited[x][y]=0;
    }
    // left
    if(issafe(x,y-1,visited,arr,n)){
        visited[x][y]=1;
        solve(x,y-1,arr,n,ans,visited,path+'L');
        visited[x][y]=0;
    }
    // RIGHT
    if(issafe(x,y+1,visited,arr,n)){
        visited[x][y]=1;
        solve(x,y+1,arr,n,ans,visited,path+'R');
        visited[x][y]=0;
    }
    // UP
    if(issafe(x-1,y,visited,arr,n)){
        visited[x][y]=1;
        solve(x-1,y,arr,n,ans,visited,path+'U');
        visited[x][y]=0;
    }

}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    vector<string>ans;
    string path="";

    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,arr,n,ans,visited,path);
    return ans;
}