/*


->DAG  directed Acyclic Graph

Linear Ordering of Vertices such That 
for every edge u-v, u always appear before v in ordering


it can also be used for cycle detection ,
if valid topo sort is not found then cycle present

*/






#include <bits/stdc++.h> 

 void toposort(int node,vector<bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adjList){
     visited[node]=1;
     for(auto neighbour:adjList[node]){
         if(!visited[neighbour]){
            toposort(neighbour,visited,s,adjList);
         }
     }
     s.push(node);
 }

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
     unordered_map<int,list<int>> adjList;
    for(int i=0; i<e;i++){
        int u= edges[i][0];
        int v= edges[i][1];
        
        adjList[u].push_back(v);
        
    }
    // unordered_map<int,bool>visited;
    vector<bool>visited(v);
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            toposort(i,visited,s,adjList);

        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return  ans;
}