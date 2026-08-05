#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
// template <typename T>
class Graph{
    public:
        unordered_map<int,list<int>>adj;

        void addEdge(int u,int v,bool direction){

            // dirn->0->undirected
            // dirn->1->directed

            // create an edge from u to v;
 
            adj[u].push_back(v);

            if(direction==0){
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<< j<<",";
                }cout<<endl;
            }
        }
};  



int main(){
    int n;
    cout<<"Enter the no of Nodes:";

    cin>>n;
    int m;
    cout<<"Enter the no of Edges:";

    cin>>m;

    Graph g;


    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u,v,0);
            

        }
        // printing graph;
        g.printAdjList();


}