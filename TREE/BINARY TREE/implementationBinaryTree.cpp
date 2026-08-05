#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// build from Preordern Traversal
static int idx=-1;
Node*buildTree2(vector<int>preorder){
    idx++;
    if(preorder[idx]=-1) return NULL;
    Node*root=new Node(preorder[idx]);
    root->left=buildTree2(preorder);
    root->right=buildTree2(preorder);
    return root;
}

Node *buildTree(Node *root)
{
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter Data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter Data for inserting in right of" << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL)
        { // purana level complete ho gya
            cout << endl;

            if (!q.empty())
            { // queue still has some child node
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            } 
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// void LevelOrderTraversal(Node*root){
//     if(root==NULL){
//         return;
//     }
//     queue<Node*>q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         Node*node=q.front();
//         q.pop();
//         if(node!=NULL){
//             cout<<node->data<<" ";
//             if(node->left){
//                 q.push(node->left);
//             }
//             if(node->right){
//                 q.push(node->right);
//             }
//         }
//         else{
//             if(!q.empty()){
//                 cout<<endl;
//
//                 q.push(NULL);
//             }
//         }

//     }

// }

void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter Data For Root Node" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter Left Node For:" << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter Right Node for :" << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (curr != NULL || !st.empty())
    {
        // Traverse to the leftmost node
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        // Process the node at the top of the stack
        curr = st.top();
        st.pop();
        result.push_back(curr->val);

        // Move to the right subtree
        curr = curr->right;
    }

    return result;
}

int main()
{
    Node *root = NULL;
    // root=buildTree(root);

    // traversal(root);
    // LevelOrderTraversal(root);

    // inorder(root);
    buildFromLevelOrder(root);
    LevelOrderTraversal(root);
}