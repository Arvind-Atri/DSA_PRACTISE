#include<iostream>
#include<unordered_map>
#include<list>



// Method 1

bool checkcycle(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsvisited,unordered_map<int,list<int>>&adjList){
  visited[node]=true;
  dfsvisited[node]=true;

  for(auto neighbour:adjList[node]){
    if(!visited[neighbour]){
      bool cycledetected=checkcycle(neighbour, visited, dfsvisited, adjList);
      if(cycledetected)
      return true;
    }
    else if(dfsvisited[neighbour]){
      return true;
    }
  }
  dfsvisited[node]=false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   unordered_map<int,list<int>> adjList;
    for(int i=0; i<edges.size();i++){
        int u= edges[i].first;
        int v= edges[i].second;
        
        adjList[u].push_back(v);
        
    }
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsvisited;

    for(int i=0;i<n;i++){
      if(!visited[i]){
        bool cycle=checkcycle(i,visited,dfsvisited,adjList);
        if(cycle){
          return true;
        }
      }
    }
    return false;
}





// Method 2 -Using Topological sort ,if valid then acyclic

// if(count of nodes==no of nodes)
// then cycle is not present
// else present