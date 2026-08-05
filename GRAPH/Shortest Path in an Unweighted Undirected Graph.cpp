#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	 unordered_map<int,list<int>> adjList;
    for(int i=0; i<edges.size();i++){
        int u= edges[i].first;
        int v= edges[i].second;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        
    }
	unordered_map<int,bool>visited;
	unordered_map<int,int>parent;
	queue<int>q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		for(auto neighbour:adjList[front]){
			if(!visited[neighbour]){
				visited[neighbour]=true;
				parent[neighbour]=front;
				q.push(neighbour);
			}
		}
	}

	vector<int>ans;
	int current=t;
	ans.push_back(t);
	while(current!=s){
		current=parent[current];
		ans.push_back(current);
	}

	reverse(ans.begin(),ans.end());
	return ans;

	
}
