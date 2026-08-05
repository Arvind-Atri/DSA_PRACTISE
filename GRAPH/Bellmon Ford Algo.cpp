vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {

    

    vector<int> distance(n+1, 1e8);

 

    distance[src] = 0;  

    for(int i=1;i<n;i++){

        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int wt=edges[j][2];
            int v=edges[j][1];

            if((distance[u] + wt ) < distance[v])

                distance[v] = distance[u] + wt;

        }

    }  

    return distance;

}