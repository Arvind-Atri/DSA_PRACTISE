

class{
// Helper function to perform in-order traversal of the BST
    int solve(TreeNode* root, int &i, int k) {
        // Base case: if the node is null, return -1
        if (root == NULL) {
            return -1;
        }
        
        // Recursive case: traverse the left subtree
        int left = solve(root->left, i, k);
        
        // If a valid left result is returned (not -1), we found the k-th smallest in the left subtree
        if (left != -1) {
            return left;
        }

        // Increment the count of visited nodes
        i++;
        
        // Check if we have reached the k-th smallest node
        if (i == k) {
            return root->val; // Return the value of the k-th smallest node
        }
        
        // If not found, traverse the right subtree
        return solve(root->right, i, k);
    }
public:
    // Main function to find the k-th smallest element in the BST
    int kthSmallest(TreeNode* root, int k) {
        int i = 0; // Initialize the count of visited nodes
        return solve(root, i, k); // Call the helper function
    }
};