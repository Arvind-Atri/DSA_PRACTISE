/**

*Method 1
->find inorder of bst by sorting preorder 
->create mapping of inorder
->traverse inorder and preorder and create respective nodes
->TC-O(NlongN)
->SC-O(N)

*Method 2
->input Node and Create Bst
o(n2)


*Method 3
->initialise min and max
->by using min and max create node in left/right part
O(n)
 */
class Solution {
private:
    // Recursive function to construct the BST from preorder traversal
    TreeNode* solve(vector<int>& preorder, int mini, int maxi, int &i) {
        // Base case: if all nodes have been processed
        if (i >= preorder.size()) return NULL;

        // Check if the current value is within the valid range
        if (preorder[i] < mini || preorder[i] > maxi) return NULL;

        // Create a new TreeNode with the current value
        TreeNode* root = new TreeNode(preorder[i++]);

        // Recursively build the left subtree with updated max value
        root->left = solve(preorder, mini, root->val, i);
        
        // Recursively build the right subtree with updated min value
        root->right = solve(preorder, root->val, maxi, i);
        
        // Return the constructed root node
        return root;
    }
public:
    // Main function to generate the BST from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Initialize the range for the root node
        int mini = INT_MIN; // Minimum allowed value
        int maxi = INT_MAX; // Maximum allowed value
        int i = 0;          // Index for the current position in preorder
        
        // Start constructing the BST
        return solve(preorder, mini, maxi, i);
    }
};
