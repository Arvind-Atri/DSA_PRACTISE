
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w) {
       double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
       // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        sort(arr,arr+n,[](Item &a,Item &b){return a.value*b.weight>b.value*a.weight;});
        double ans=0;
        for(int i=0;i<n;i++){
            if(w<arr[i].weight){
                ans+=((arr[i].value*1.0)/arr[i].weight)*w;
                break;
            }
           // cout<<ans<<endl;
            w-=arr[i].weight;
            ans+=arr[i].value;
        }
        return ans;
    }
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
    }
    return 0;
}

// } Driver Code Ends