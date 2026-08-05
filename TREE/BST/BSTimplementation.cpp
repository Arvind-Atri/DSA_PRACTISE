#include<iostream>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    Node*left;
    Node*right;


    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertIntoBST(Node*& root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        root->right=insertIntoBST(root->right,data);
    }else{
       root->left= insertIntoBST(root->left,data);
    }
    return root;


}

void takeInput(Node*&root){
    int data;
    cin>>data;
    while(data!=-1){
         root=insertIntoBST(root,data);
         cout<<"ENTER DATA->"<<endl;
        cin>>data;

    }
}

void levelordertraversal(Node*root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else{
            if(!q.empty()){
                cout<<endl;
            // cout<<node->data<<" ";
                q.push(NULL);
            }
        }

    }

}

void preorder(Node*root){
    if(root==NULL){
        // cout<<endl<<"OOPS! NO data is preesent"<<endl;
        return;
    }
    else{
        cout<<root->data<<" ";
        // PRINTING LEFT PART OF THE ROOT
        preorder(root->left); 


        // PRINTING RIGHT PART OF THE ROOT
        preorder(root->right);
    }
}

void inorder(Node*root){
    if(root==NULL){
        // cout<<endl<<"OOPS! NO data is preesent"<<endl;
        return;
    }
    else{
        // PRINTING LEFT PART OF THE ROOT
        inorder(root->left); 

        cout<<root->data<<" ";

        // PRINTING RIGHT PART OF THE ROOT
        inorder(root->right);
    }
}

void postorder(Node*root){
    if(root==NULL){
        // cout<<endl<<"OOPS! NO data is preesent"<<endl;
        return;
    }
    else{
        // PRINTING LEFT PART OF THE ROOT
        postorder(root->left); 


        // PRINTING RIGHT PART OF THE ROOT
        postorder(root->right);
        cout<<root->data<<" ";
    }
}



// node* minval(node*root){
//     node*temp=root;
//     while(temp->left!=NULL){
//         temp=temp->left;
//     }
//     return temp;
// }

// node*deletefrombst(node*root,int data){
//     if(root==NULL){
//         return root;
//     }
//     if(root->data==data){ 
//         //0 child
//         if(root->left==NULL&&root->right==NULL){
//             delete root;
//             return NULL;
//         }
//         //1 child
//         if(root->left!=NULL&&root->right==NULL){
//             node*temp=root->left;
//             delete root;
//             return temp;  //return child as a node
//         }

//         if(root->left==NULL&&root->right!=NULL){
//             node*temp=root->right;
//             delete root;
//             return temp;  //return child as a node
//         }

//         //2 child
//         if(root->left!=NULL&&root->right!=NULL){
               ///successor
//             int mini=minval(root->right)->data;
//             root->data=mini;
//             root->right=deletefrombst(root->right,mini);
//             return root;
//         }
//     }
//     else if(data>root->data){
//         root->right= deletefrombst(root->right,data);
//         return root;
//     }
//     else{
//         root->left= deletefrombst(root->left,data);
//         return root;
//     }
// }

int main(){
    Node*root=NULL;
    cout<<"Enter Data to create BST:"<<endl;
    takeInput(root);


    cout<<"PRinting root data"<<endl;
    cout<<root->data;

    cout<<"------LEVEL ORDER  BST------"<<endl;
    levelordertraversal(root);
    cout<<endl<<"PREORDER TRAVERSAL"<<endl;
   
    preorder(root);
    cout<<endl<<"INORDER TRAVERSAL"<<endl;
    inorder(root);
    cout<<endl<<"POSTORDER TRAVERSAL"<<endl;
    postorder(root);





    return 0;
}