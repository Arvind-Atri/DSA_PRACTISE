


void inorder(){

}



Node*Flatten(Node*root){
    vector<int>inorderVal;
    inorder();

    Node*newRoot=new Node(inorderVal[0]);


    Node*curr=newRoot;

    for(int i=1;i<inorderVal.size();i++){
        Node* temp=new Node(inorderVal[i]);

        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    curr->left=NULL;
    curr->right=NULL;
    return newRoot;

}