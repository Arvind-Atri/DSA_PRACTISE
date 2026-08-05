// Method 1-Iterative
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int r = 0;
            while (n--) {
                auto cur = q.front(); q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                r = cur->val;
            }
            v.push_back(r);
        }
        return v;
        
    }
};




// Method 2-Recursive

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
private:
    void solve(TreeNode*root,vector<int>&ans,int level){
        if(root==NULL){
            return;
        }
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
       
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root,ans,0);
        return ans;
    }
};