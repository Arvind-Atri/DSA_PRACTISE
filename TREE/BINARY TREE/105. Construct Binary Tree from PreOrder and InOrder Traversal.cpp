


// T.C=O(n*n);
// S.C=O(1);



class Solution {
private:
    int findPosition(vector<int> in, int element, int n) {   //O(n)
        for (int i = 0; i < n; i++) {
            if (in[i] == element)
                return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int> in, vector<int> pre, int& index, 
                    int inorderStart, int inorderEnd, int n) {  // O(n*n)
        // base case
        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(in, element, n);

        // recursive call
        root->left = solve(in, pre, index, inorderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        TreeNode* ans = solve(inorder, preorder, preOrderIndex, 0,
                              inorder.size() - 1, preorder.size());
        return ans;
    }
};




// Using Map


// T.C=O(n*logN);
// S.C=O(n);


class Solution {
private:
    int createMapping(vector<int> in, map<int,int>&nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[in[i]]=i;
        }
        return -1;
    }
    TreeNode* solve(vector<int> in, vector<int> pre, int& index,
                    int inorderStart, int inorderEnd, int n,map<int,int>nodeToIndex) {
        // base case
        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        // recursive call
        root->left = solve(in, pre, index, inorderStart, position - 1, nodeToIndex);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n,nodeToIndex);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        map<int,int>nodeToIndex;
        createMapping(inorder,nodeToIndex,inorder.size());
        TreeNode* ans = solve(inorder, preorder, preOrderIndex, 0,
                              inorder.size() - 1, preorder.size(),nodeToIndex);
        return ans;
    }
};


