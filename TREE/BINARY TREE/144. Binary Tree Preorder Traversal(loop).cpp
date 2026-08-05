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
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
            return result; // Handle empty tree case

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();

            // Process the current node
            result.push_back(curr->val);

            // Push right child first, so left is processed first
            if (curr->right)
            {
                st.push(curr->right);
            }
            if (curr->left)
            {
                st.push(curr->left);
            }
        }

        return result;
    }
};