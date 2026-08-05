#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
};

class info{
    public:
    int min;
    int max;
    int sz;

    info(int cn,int cx,int cz){
        min=cn;
        max=cx;
        sz=cz;
    }
};
info helper(Node*root){
    if(root==NULL) return info(INT16_MAX,INT16_MIN,0);

    info left=helper(root->left);
    info right= helper(root->right);

    if(root->data > left.max && root->data <right.max){
        int currMin=min(root->data,left.min);
        int currMax=max(root->data,right.max);
        int currSz= left.sz+right.sz+1;
        return info(currMin,currMax,currSz);

    }
    return info(INT16_MIN,INT16_MAX,max(left.sz,right.sz));
}


int largestBSTinBT(Node*root){
    info info =helper(root);
    return info.sz;
}
