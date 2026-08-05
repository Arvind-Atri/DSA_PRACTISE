// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) 
//     {
//         set<int>st(begin(arr), end(arr));

//         int rankNumber = 1;
//         unordered_map<int, int>rank;
//         for(auto val:st)
//             rank[val] = rankNumber++;

//         for(auto &val:arr)
//             val = rank[val];
//         return arr;
//     }
// };




class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>rank;
        int currRank = 0;
        for(int i = 0; i < temp.size(); i++){
            if(i == 0){
                currRank++;
                rank[temp[i]] = currRank;
            }
            else{
                if(temp[i-1] == temp[i]) continue;
                else{
                    currRank++;
                    rank[temp[i]] = currRank;
                    
                }
            }
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
        
    }
};