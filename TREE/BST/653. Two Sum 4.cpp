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
    // Helper function to perform inorder traversal and collect node values in a vector
    void inorder(vector<int>& arr, TreeNode* root) {
        if (root == NULL) {
            return;  // If root is NULL, exit the function
        }
        inorder(arr, root->left);  // Traverse left subtree
        arr.push_back(root->val);  // Add root node's value to the array
        inorder(arr, root->right); // Traverse right subtree
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;  // To store inorder traversal values (sorted order)
        inorder(arr, root);  // Perform inorder traversal and fill arr

        // Use two pointers to check for target sum
        int i = 0;  // Left pointer starting at the beginning of the array
        int j = arr.size() - 1;  // Right pointer starting at the end of the array

        // Two-pointer approach to find if any two numbers add up to k
        while (i < j) {
            int sum = arr[i] + arr[j];
            
            if (sum == k) {  // If the sum of values at two pointers equals k
                return true; // Found the target sum, return true
            }
            else if (sum > k) {  // If sum is greater than k
                j--;  // Move the right pointer to the left to decrease the sum
            }
            else {
                i++;  // If sum is less than k, move the left pointer to the right to increase the sum
            }
        }

        // If no such pair is found, return false
        return false;
    }
};
