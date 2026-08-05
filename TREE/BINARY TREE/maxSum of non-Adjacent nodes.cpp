 pair<int,int>solve(Node*root){
    if(root==NULL){
        pair<int,int>p=make-pair(0,0);
        return p;
    }
    pair<int,int>left=solve(root->left);
    pair<int,int>right=solve(root->right);

    pair<int,int>res;
    res.first=root->data+left.second+right.second; //inc
    res.second=max(left.first,left.second)+max(right.first,right.second);  //excl 
    return res;
}
int getMaxSum(Node*root){
    pair<int,int>ans=solve(root);
    return max(ans.first,ans.second);
}