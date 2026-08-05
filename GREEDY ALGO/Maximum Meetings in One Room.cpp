//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
      vector<pair<int,int>>v;
        
        for(int i=0;i<N;i++){
            pair<int,int>p=make_pair(S[i],F[i]);
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        vector<int> ans;
        ans.push_back(1);
        int ansEnd=v[0].second;
        
        for(int i=1;i<N;i++){
            if(v[i].first>ansEnd){
                ans.push_back(i+1);
                ansEnd=v[i].second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends