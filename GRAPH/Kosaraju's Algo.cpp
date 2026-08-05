#include<unordered_map>

#include<list>

#include<stack>

// TC=O(N+E)

void dfs(int node, vector<int> &visited, unordered_map<int, list<int>> &adj, stack<int> &stk){

    visited[node] = true;

 

    for(auto neighbour:adj[node]){

        if(!visited[neighbour]){

            dfs(neighbour, visited, adj, stk);

        }

    }  

    stk.push(node);

}

void reverseDFS(int node, vector<int> &visited, unordered_map<int, list<int>> &adj){

    visited[node] = true;

 

    for(auto neighbour:adj[node]){

        if(!visited[neighbour]){

            reverseDFS(neighbour, visited, adj);

        }

    }

}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)

{

    unordered_map<int, list<int>> adj;  

    for(int i=0;i<edges.size();i++){

        adj[edges[i][0]].push_back(edges[i][1]);

    }  

    vector<int> visited(v, false);

    stack<int> stk;  

    // Step 01 -> Topological Sort:

    for(int i=0;i<v;i++){

        if(!visited[i]){

            dfs(i, visited, adj, stk);

        }

    }  

    // Step 02 -> Transpose:

    unordered_map<int, list<int>> transpose;

    

    for(int i=0;i<v;i++){

        visited[i] = false;

        for(auto neighbour:adj[i]){

            transpose[neighbour].push_back(i);

        }

    }  

    // Step 03 -> Do DFS call using above ordering:

    int count = 0;

    while(!stk.empty()){

        int top = stk.top();

        stk.pop();  

        if(!visited[top]){

            count++;

            reverseDFS(top, visited, transpose);

        }

    }  

    return count;

}