pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    if (!root)
        return {-1, -1};

    int pred = -1, succ = -1;
    TreeNode *temp = root;

    // Traverse the tree to find the key or its position
    while (temp)
    {
        if (temp->data == key)
        {
            break; // Key found
        }
        if (key < temp->data)
        {
            succ = temp->data; // Update successor
            temp = temp->left;
        }
        else
        {
            pred = temp->data; // Update predecessor
            temp = temp->right;
        }
    }

    // If the key is not found in the tree
    if (!temp)
    {
        return {pred, succ}; // Return tracked predecessor and successor
    }

    // Find predecessor: rightmost node in the left subtree
    TreeNode *leftTree = temp->left;
    while (leftTree)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // Find successor: leftmost node in the right subtree
    TreeNode *rightTree = temp->right;
    while (rightTree)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}
