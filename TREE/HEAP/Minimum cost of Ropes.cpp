//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// T.c-O(NlogN)
// S.c- O(n)

// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long ,vector<long long >,greater<long long >>pq;
        
        long long int cost=0;
        
        for(auto i:arr){
            pq.push(i);
        }
        
        while(pq.size()>1){
            long long int a=pq.top();
            pq.pop();
            
            long long int b=pq.top();
            pq.pop();
            long long sum=a+b;
            cost+=sum;
            pq.push(sum);
            
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends