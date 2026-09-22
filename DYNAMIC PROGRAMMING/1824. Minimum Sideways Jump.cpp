// class Solution {
// public:

//     int solveRec(vector<int>&obstacles,int currLane,int currPos){
//         if(currPos==obstacles.size()-1) return 0;

//         if(obstacles[currPos+1]!=currLane){
//             // Moving Forward is Safe for now
//             return solveRec(obstacles,currLane,currPos+1);
//         }
//         else{
//             // have to jump sideways
//             int ans=INT_MAX;
//             for(int lane=1;lane<=3;lane++){
//                 if(lane!=currLane and obstacles[currPos]!=lane)
//                 ans=min(ans,1+solveRec(obstacles,lane,currPos));
//             }
//             return ans;
//         }
//     }
//     int minSideJumps(vector<int>& obstacles) {
//         return solveRec(obstacles,2,0);
//     }
// };

// class Solution {
// public:
//     int solveRec(vector<int>& obstacles, int currLane, int currPos,
//                  vector<vector<int>>& dp) {
//         if (currPos == obstacles.size() - 1)
//             return 0;

//         if (dp[currLane][currPos] != -1)
//             return dp[currLane][currPos];

//         if (obstacles[currPos + 1] != currLane) {
//             // Moving Forward is Safe for now
//             return solveRec(obstacles, currLane, currPos + 1, dp);
//         } else {
//             // have to jump sideways
//             int ans = INT_MAX;
//             for (int lane = 1; lane <= 3; lane++) {
//                 if (lane != currLane and obstacles[currPos] != lane)
//                     ans = min(ans, 1 + solveRec(obstacles, lane, currPos, dp));
//             }
//             return dp[currLane][currPos] = ans;
//         }
//     }
//     int minSideJumps(vector<int>& obstacles) {
//         vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
//         return solveRec(obstacles, 2, 0, dp);
//     }
// };

class Solution {
public:
    // int solveTab(vector<int>& obstacles) {
    //     int n = obstacles.size() - 1; // denoting index
    //     vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));

    //     dp[0][n] = 0;
    //     dp[1][n] = 0;
    //     dp[2][n] = 0;
    //     dp[3][n] = 0;

    //     for (int currPos = n - 1; currPos >= 0; currPos--) {
    //         for (int currLane = 1; currLane <= 3; currLane++) {
    //             if (obstacles[currPos + 1] != currLane) {
    //                 // Moving Forward is Safe for now
    //                 dp[currLane][currPos]=dp[currLane][currPos + 1];
    //             } else {
    //                 // have to jump sideways
    //                 int ans = 1e9;
    //                 for (int lane = 1; lane <= 3; lane++) {
    //                     if (lane != currLane and obstacles[currPos] != lane)
    //                         ans = min(ans,
    //                                   1 + dp[lane][currPos+1]);
    //                 }
    //                 dp[currLane][currPos]= ans;
    //             }
    //         }
    //     }
    //     return min(dp[2][0],min(1+dp[3][0],1+dp[1][0]));
    // }

    int solveTabSO(vector<int>& obstacles) {
        int n = obstacles.size() - 1; // denoting index
        // vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));
        vector<int>curr(4,INT_MAX);
        vector<int>next(4,INT_MAX);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--) {
            for (int currLane = 1; currLane <= 3; currLane++) {
                if (obstacles[currPos + 1] != currLane) {
                    // Moving Forward is Safe for now
                    curr[currLane]=next[currLane];
                } else {
                    // have to jump sideways
                    int ans = 1e9;
                    for (int lane = 1; lane <= 3; lane++) {
                        if (lane != currLane and obstacles[currPos] != lane)
                            ans = min(ans,
                                      1 + next[lane]);
                    }
                    curr[currLane]= ans;
                }
            }

            next=curr;
        }
        return min(next[2],min(1+next[3],1+next[1]));
    }
    int minSideJumps(vector<int>& obstacles) {
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        return solveTabSO(obstacles);
    }
};
