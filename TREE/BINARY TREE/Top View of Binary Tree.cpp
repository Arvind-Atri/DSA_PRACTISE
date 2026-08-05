

/*
FIND

If the key is found, it returns an iterator to the position where the key is present in the map.
If the key is not found, it returns an iterator to the end of the map. 
*/

/*
END

end() function is used to return an iterator pointing to past the last element of the map container. Since it does not refer to a valid element, it cannot de-referenced end() function returns a bidirectional

*/

vector<int>topView(Node*root){
    vector<int>ans;
    if(root=NULL){
        return ans;
    }

    map<int,int>topNode;
    queue<pair<Node*,int>>q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int>temp=q.front();
        q.pop();
        Node*frontNode=temp.first;
        int hd=temp.second;

        // mapping one->one

        if(topNode.find(hd)==topNode.end()){
            topNode[hd]=frontNode->data;
        }
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1))
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1))
        }
    }
 
    //#crucial Part-> ans depends on mapping
    for(auto i:topNode){
        ans.push_back(i.second);

    }
    return ans;
}