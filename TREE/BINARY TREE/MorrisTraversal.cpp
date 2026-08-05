class Solution
{
public:
    vector<int> morrisInOrderTraversal(Node *root)
    {
        vector<int> result;
        Node *current = root;

        while (current != NULL)
        {
            if (current->left == NULL)
            {
                // No left subtree, visit the node
                result.push_back(current->data);
                current = current->right; // Move to the right subtree
            }
            else
            {
                // Find the inorder predecessor
                Node *predecessor = current->left;
                while (predecessor->right != NULL && predecessor->right != current)
                {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == NULL)
                {
                    // Create a thread to the current node
                    predecessor->right = current;
                    current = current->left; // Move to the left subtree
                }
                else
                {
                    // Thread exists, restore the tree structure
                    predecessor->right = NULL;
                    result.push_back(current->data); // Visit the node
                    current = current->right;        // Move to the right subtree
                }
            }
        }

        return result;
    }
};
