class Solution {
public:
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left,
              int right) {
        if (left == right)
            return 0;

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                               solve(arr, maxi, left, i) +
                               solve(arr, maxi, i + 1, right));
        }
        return ans;
    }
    int solveMem(vector<int>& arr, map<pair<int, int>, int>& maxi, int left,
                 int right, vector<vector<int>>& dp) {
        if (left == right)
            return 0;
        if (dp[left][right] != -1)
            return dp[left][right];

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                               solveMem(arr, maxi, left, i, dp) +
                               solveMem(arr, maxi, i + 1, right, dp));
        }
        return dp[left][right] = ans;
    }
int solveTab(vector<int>& arr, map<pair<int,int>,int>& maxi) {
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // length = 2 because length 1 already has cost 0
    for (int len = 2; len <= n; len++) {

        for (int left = 0; left + len - 1 < n; left++) {

            int right = left + len - 1;
            int ans = INT_MAX;

            for (int i = left; i < right; i++) {

                int cost = maxi[{left, i}] *
                           maxi[{i + 1, right}];

                cost += dp[left][i];
                cost += dp[i + 1][right];

                ans = min(ans, cost);
            }

            dp[left][right] = ans;
        }
    }

    return dp[0][n - 1];
}
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(arr,maxi,0,n-1);
        // return solveMem(arr, maxi, 0, n - 1, dp);
        return solveTab(arr,maxi);
    }
};
