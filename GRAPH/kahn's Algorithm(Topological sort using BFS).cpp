




/*

find indegree of all nodes

queue->push all 0 indegree nodes


do bfs

*/



#include <bits/stdc++.h> 


//  T.c=S.c=O(N+E)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
     unordered_map<int,list<int>> adjList;
    for(int i=0; i<e;i++){
        int u= edges[i][0];
        int v= edges[i][1];
        
        adjList[u].push_back(v);
        
    }
   
    vector<int>indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    //0 indegree walo ko push krdo

    queue<int>q;

    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int>ans;
    while(!q.empty()){
        int front =q.front();
        q.pop();

        ans.push_back(front);

        //neighbour indegree update

        for(auto neighbour :adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
                q.push(neighbour);
        }
    }


    return ans;

    
}