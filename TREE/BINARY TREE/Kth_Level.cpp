#include<iostream>
using namespace std;


void K_Level(Node*root,int k){
    if(root==NULL) return;
    if(k==1){
        cout<<root->data;
        return;
    }
    K_Level(root->left,k-1);
    K_Level(root->right,k-1);
    
}

int main(){

}