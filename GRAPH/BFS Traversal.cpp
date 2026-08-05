#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
using namespace std;







void bfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i: adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    unordered_map<int, bool> visited;
    bfs(adj, visited, ans, 0);
    return ans;
}









//if adj List is not given 


void printAdjList(const unordered_map<int, list<int>> &adjList) {
    for (const auto &i : adjList) {
        cout << i.first << " -> ";
        for (const auto &j : i.second) {
            cout << j << ", ";
        }
        cout << endl;
    }
}

void preparAdjList(unordered_map<int,list<int>> &adjList, const vector<vector<int>> &adj, int n) {
    // Initialize all nodes in adjList
    // for (int i = 0; i < n; i++) {
    //     adjList[i] = list<int>(); // Ensure every node is present in the adjacency list
    // }

    for (const auto &edge : adj) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }
}

void bfs(const unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (const auto &i : adjList.at(frontNode)) { // Use .at() for safety
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, const vector<vector<int>> &adj) {
    unordered_map<int,list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    preparAdjList(adjList, adj, n);

    // Traverse all components 
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans; // Only return once
}

// Example usage
int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}};
    
    vector<int> bfsResult = bfsTraversal(n, edges);
    
    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}





