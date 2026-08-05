/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>nodes;
        // queue<pair<TreeNode*,pair<hd,level>>>q;
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>> finally;


        if(root==NULL){
            return finally;
        }

        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty()){
            pair<TreeNode*,pair<int,int>>temp=q.front();
            q.pop();
            TreeNode*frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val);

            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
        }
        for (auto i : nodes) {
            vector<int> ans;
            for (auto j : i.second) {
                vector<int> values = j.second;
                sort(values.begin(), values.end());
                ans.insert(ans.end(), values.begin(), values.end());
            }
            finally.push_back(ans);
        }
        return finally;
    }
};



// OPTIMISED for Better Readability

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void print(vector<int>arr){
        for(auto i:arr){
            cout<<i<<" ";
        }cout<<endl;
    }
public:
     vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int, map<int, vector<int>>> nodes; // hd -> level -> values
        queue<pair<TreeNode*, pair<int, int>>> q; // node, (hd, level)
        vector<vector<int>> finally;

        if (root == NULL) {
            return finally;
        }

        q.push({root, {0, 0}}); // starting with the root node at hd = 0, level = 0

        while (!q.empty()) {
            auto [frontNode, coords] = q.front(); // structured bindings for clarity
            q.pop();
            int hd = coords.first;
            int lvl = coords.second;

            nodes[hd][lvl].push_back(frontNode->val);

            if (frontNode->left) {
                q.push({frontNode->left, {hd - 1, lvl + 1}});
            }
            if (frontNode->right) {
                q.push({frontNode->right, {hd + 1, lvl + 1}});
            }
        }
for (const auto& [hd, levelMap] : nodes) {
    vector<int> ans;
    for (const auto& [lvl, values] : levelMap) {
        vector<int> sortedValues = values; // Copy the values
        sort(sortedValues.begin(), sortedValues.end()); // Sort the copied values
        ans.insert(ans.end(), sortedValues.begin(), sortedValues.end()); // Append sorted values to ans
    }
    finally.push_back(ans); // Add the complete vertical order to the result
}



        
        return finally;
    }
};