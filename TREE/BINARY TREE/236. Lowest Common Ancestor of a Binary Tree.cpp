
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==NULL){
//             return NULL;
//         }
//         if(root->val==p->val || root->val==q->val){
//             return root;
//         }

//         TreeNode*left=lowestCommonAncestor(root->left,p,q);
//         TreeNode*right=lowestCommonAncestor(root->right,p,q);

//         if(left!=NULL && right!=NULL){
//             return root;
//         }
//         else if(left!=NULL && right==NULL){
//             return left;
//         }
//        else if(left==NULL && right!=NULL){
//             return right;
//         }
//         else {
//             return NULL;
//         }
        
//     }
// };



// CLEAN CODE

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        
        if(root->val==p->val||root->val==q->val)
            return root;
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(left && right) return root;
        if(left && !right)return left;
        if(!left && right)return right;
        return NULL;  
    }
};