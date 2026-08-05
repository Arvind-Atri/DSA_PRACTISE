




// TC-O(n)
// SC-O(n)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // Default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor with value
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // Constructor with value and children
 * };
 */

class Solution {
private:
    // Helper function to find the minimum value node in a subtree
    TreeNode* minVal(TreeNode* root) {
        TreeNode* temp = root;

        // Traverse to the leftmost node
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp; // Return the minimum value node
    }

    // Recursive function to delete a node from the BST
    TreeNode* deleteFromBST(TreeNode* root, int val) {
        // Base case: if the root is null, nothing to delete
        if (root == NULL) {
            return root;
        }

        // If the value to be deleted is found
        if (root->val == val) {
            // Case 1: Node has no children (leaf node)
            if (root->left == NULL && root->right == NULL) {
                delete root; // Free the memory
                return NULL; // Return null to the parent
            }
            
            // Case 2: Node has only a left child
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left; // Temporarily store the left child
                delete root; // Free the current node
                return temp; // Return the left child to the parent
            }
            // Case 3: Node has only a right child
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right; // Temporarily store the right child
                delete root; // Free the current node
                return temp; // Return the right child to the parent
            }

            // Case 4: Node has two children
            if (root->left != NULL && root->right != NULL) {
                // Find the minimum value in the right subtree
                int mini = minVal(root->right)->val; // Get the minimum value
                root->val = mini; // Replace the value with the minimum value
                // Delete the minimum value node from the right subtree
                root->right = deleteFromBST(root->right, mini);
                return root; // Return the updated root
            }
        } 
        // If the value to be deleted is smaller, go to the left subtree
        else if (root->val > val) {
            root->left = deleteFromBST(root->left, val);
            return root; // Return the updated root
        } 
        // If the value to be deleted is larger, go to the right subtree
        else {
            root->right = deleteFromBST(root->right, val);
            return root; // Return the updated root
        }

        return root; // Return the root (not needed, but keeps the function signature valid)
    }

public:
    // Public function to delete a node given its key
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteFromBST(root, key); // Call the helper function
    }
};
