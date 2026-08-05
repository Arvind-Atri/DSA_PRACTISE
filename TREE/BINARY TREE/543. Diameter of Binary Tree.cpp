
class Solution {
private:
     int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        int height=max(left,right)+1;

        return height;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
        int op3=maxDepth(root->left)+maxDepth(root->right);

        int ans=max(op1,max(op2,op3));
        return ans;
    }
};



// Method 2


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
        1
       / \
      2   3
     / \
    4   5
pair<int,int> diameterFast(TreeNode*root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;

    }
    pair<int,int>left=diameterFast(root->left);
    pair<int,int>right=diameterFast(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second;

    pair<int,int>ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {


        return diameterFast(root).first;
        // if(root==NULL){
        //     return 0;
        // }
        // int op1=diameterOfBinaryTree(root->left);
        // int op2=diameterOfBinaryTree(root->right);
        // int op3=maxDepth(root->left)+maxDepth(root->right);

        // int ans=max(op1,max(op2,op3));
        // return ans;
    }
};





//3  

heigh of lef +righ +1