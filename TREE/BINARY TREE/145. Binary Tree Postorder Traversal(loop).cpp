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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
            return result; // Handle empty tree case

        stack<TreeNode *> st;
        TreeNode *prev = NULL;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *curr = st.top();

            // If traversing down the tree
            if (prev == NULL || prev->left == curr || prev->right == curr)
            {
                if (curr->left)
                {
                    st.push(curr->left);
                }
                else if (curr->right)
                {
                    st.push(curr->right);
                }
                else
                {
                    st.pop();
                    result.push_back(curr->val);
                }
            }
            // If traversing up the tree from the left
            else if (curr->left == prev)
            {
                if (curr->right)
                {
                    st.push(curr->right);
                }
                else
                {
                    st.pop();
                    result.push_back(curr->val);
                }
            }
            // If traversing up the tree from the right
            else if (curr->right == prev)
            {
                st.pop();
                result.push_back(curr->val);
            }

            prev = curr;
        }

        return result;
    }
};