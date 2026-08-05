Node*solve(Node*root,int&k,int node){
    if(root==NULL){
        return NULL;
    }

    if(root->data==node){
        return root;
    }
    
    Node*left=solve(root->left,k,noed);
    Node*right=solve(root->right,k,node);
     
     if(left!=NULL && right==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftAns;
     }
     if(left==NULL && right!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftAns;
     }
     return NULL;

}


int KthAncestor(Node*root,int k,int node){
    Node*ans=solve(root,k,node);
    if(ans==NULL || ans->data==node){
        return -1;
    }
    else{
        return ans->data;
    }
}