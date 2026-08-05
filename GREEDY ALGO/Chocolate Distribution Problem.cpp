//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMinDiff(vector<int> arr, int m) {
        sort(arr.begin(),arr.end());
        int i=0;
        int j=m-1;
        
        
        int mini=INT_MAX;
        while(j<arr.size()){
            int diff=arr[j]-arr[i];
            mini=min(mini,diff);
            i++;j++;
        }
        return mini;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int m;
        cin >> m;
        cin.ignore();
        Solution ob;
        cout << ob.findMinDiff(arr, m) << endl;
    }
    return 0;
}
// } Driver Code Ends