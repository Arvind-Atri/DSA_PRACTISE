 void solve(Node*root,int k,int &count,vector<int>&paths){
    if(!root)return;

    path.push_back(root->val);
    solve(root->left,k,count,paths)
    solve(root->right,k,count,paths)


    int sum = path.size();

    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k)
        count++;
    }
    path.pop_back();

}

int sum(Node*root,int K){
    vector<int>Paths;
    int count=0;
    solve(root,k,count,path);
    return count;
}