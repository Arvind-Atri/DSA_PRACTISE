

// Method 1 Recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL; // Base case: root is NULL
        
        if(root->val < p->val && root->val < q->val) {
            // Both p and q are greater than root, move to the right subtree
            return lowestCommonAncestor(root->right, p, q);
        }
        
        if(root->val > p->val && root->val > q->val) {
            // Both p and q are smaller than root, move to the left subtree
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // If we reach here, root is the lowest common ancestor
        return root;
    }
};






// Method 2 Iterative
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL){
            if(root->val<p->val && root->val < q->val){
           root=root->right;
        }
        else if(root->val>p->val && root->val > q->val){
            root=root->left;
        }
        }
        else{
            return root;
        }

      
    }