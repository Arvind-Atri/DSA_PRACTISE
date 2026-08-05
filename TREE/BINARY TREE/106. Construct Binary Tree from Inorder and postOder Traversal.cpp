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
    int createMapping(vector<int> in, map<int,int>&nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[in[i]]=i;
        }
        return -1;
    }
    TreeNode* solve(vector<int> in, vector<int> post, int& index,
                    int inorderStart, int inorderEnd, int n,map<int,int>nodeToIndex) {
        // base case
        if (index <0|| inorderStart > inorderEnd) {
            return NULL;
        }
        int element = post[index--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        // recursive call
        root->right = solve(in, post, index, position + 1, inorderEnd, n,nodeToIndex);
        root->left = solve(in, post, index, inorderStart, position - 1,n, nodeToIndex);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int postOrderIndex = postorder.size()-1;
        map<int,int>nodeToIndex;
        createMapping(inorder,nodeToIndex,inorder.size());
        TreeNode* ans = solve(inorder, postorder, postOrderIndex, 0,
                              inorder.size() - 1, postorder.size(),nodeToIndex);
        return ans;
    }
};