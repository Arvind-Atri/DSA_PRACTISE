class Solution
{
public:
    void leftView(Node *root, vector<int> &ans, int lvl)
    {
        if (root == NULL)
            return;

        if (lvl == ans.size())
        {
            cout << "LVL" << lvl << endl;
            cout << "size" << ans.size() << endl;
            cout << "D" << root->data << endl
                 << endl;

            ans.push_back(root->data);
        }

        leftView(root->left, ans, lvl + 1);
        leftView(root->right, ans, lvl + 1);
    }
    vector<int> leftView(Node *root)
    {
        vector<int> ans;
        leftView(root, ans, 0);
        return ans;
    }
};