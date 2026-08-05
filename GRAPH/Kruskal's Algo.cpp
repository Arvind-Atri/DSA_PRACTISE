#include <bits/stdc++.h>
 
//solved using priority queue
void makeSet(vector<int> &parent,vector<int> &rank,int n){
  for(int i = 0; i< n; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}
int findParent(vector<int>&parent,int node){
  if(parent[node] == node){
    return node;
  }
  return parent[node] = findParent(parent, parent[node]); 
}
void unionSet(vector<int> &parent,vector<int> &rank,int u,int v){
  // u = findParent(parent, u);
  // v = findParent(parent, v);
  if(rank[u] < rank[v])
    parent[u] = v;
  else if(rank[v] < rank[u])
    parent[v] = u;
  else {
    parent[v] = u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent,rank,n);

  int minWeight = 0;
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
  
  for(int i = 0; i< edges.size(); i++){
    pq.push({edges[i][2],{edges[i][0],edges[i][1]}});
  }

  while(!pq.empty()){
    auto top = pq.top();
    pq.pop();
    int u = findParent(parent, top.second.first);
    int v = findParent(parent, top.second.second);
    int wt = top.first;
    if (u != v) {
      minWeight += wt;
      unionSet(parent, rank, u, v);
    }
  }
  return minWeight;
}


sort(vector<int>&a,Vector,int>&b){
  return a[2]<b[2];
} 

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
  sort(edges.begin(),edges.end(),cmp);
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n);

  int minWeight = 0;
   
  for (int i = 0; i < edges.size(); i++)
  {
    int u=findParent(parent,edges[i][0]);
    int v=findParent(parent,edges[i][1]);
    int wt=edges[i][2];
    if (u != v)
    {
      minWeight += wt;
      unionSet(parent, rank, u, v);
    }
  }

 
  return minWeight;
}