
/*

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

*/

class Solution {
private:
    // Helper function to validate if a tree is a binary search tree (BST)
    bool isBST(TreeNode* root, long long int min, long long int max) {
        // Base case: if the current node is null, it is a valid subtree
        if (root == NULL) {
            return true;
        }
        
        // Check if the current node's value is within the valid range
        if (root->val > min && root->val < max) {
            // Recursively check the left and right subtrees
            // The left child's value must be within (min, root->val)
            bool left = isBST(root->left, min, root->val);
            // The right child's value must be within (root->val, max)
            bool right = isBST(root->right, root->val, max);
            
            // Return true only if both left and right subtrees are valid
            return left && right;
        } else {
            // If the current node's value is out of range, return false
            return false;
        }
    }
}
    // Main function to check if the entire tree is a vali
