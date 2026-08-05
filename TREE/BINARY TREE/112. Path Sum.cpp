/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;                // Value of the current node
 *     TreeNode *left;         // Pointer to the left child
 *     TreeNode *right;        // Pointer to the right child
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}                // Default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}           // Constructor with value initialization
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  // Full constructor
 * };
 */

class Solution {
private:
    // Helper function to check if there is a root-to-leaf path with the given target sum
    bool solve(TreeNode* root, int targetSum, int sum) {
        // Base case: If the current node is NULL, return false (no path through this node)
        if (root == NULL) {
            return false;
        }

        // Add the current node's value to the running sum
        sum = sum + root->val;

        // Check if we are at a leaf node (both left and right children are NULL)
        if (root->left == NULL && root->right == NULL) {
            // If the sum at this leaf node is equal to the target sum, return true
            if (sum == targetSum) {
                return true;
            } else {
                return false;  // Otherwise, return false
            }
        }

        // Recursively check the left and right subtrees
        bool left = solve(root->left, targetSum, sum);   // Check left subtree
        bool right = solve(root->right, targetSum, sum); // Check right subtree

        // Return true if either left or right subtree has a valid path with targetSum
        return left || right;
    }

public:
    // Main function to check if a root-to-leaf path with targetSum exists
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;  // Initialize sum to 0
        return solve(root, targetSum, sum);  // Start the recursive function
    }
};
