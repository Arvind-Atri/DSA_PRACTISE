void inorder(TreeNode *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}

vector<int> mergeArray(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }
    while (i < a.size())
    {

        ans[k++] = a[i++];
    }
    while (j < b.size())
    {

        ans[k++] = b[j++];
    }
    return ans;
}

TreeNode *inorderToBST(int s, int e, vector<int> in)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;

    TreeNode *root = new TreeNode(in[mid]);
    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);
    return root;
}

int main()
{
    // save inorder for both bst-O(m)

    // merge both inorder in sorted fashion-O(n)

    // create bst from new inorder
}

// MUST ATTEMPT
// https://leetcode.com/problems/merge-bsts-to-create-single-bst/