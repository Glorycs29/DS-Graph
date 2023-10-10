class DSU{
private:

    int *parent;
    int *size;

public:

    DSU(int v){
        size = new int[v];
        parent = new int[v];
        for(int i = 0; i < v; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int Find(int node){
        if(parent[node] != node){
            return parent[node] = Find(parent[node]); // path compression step.
        }
        return node;
    }

    void Union(int u,int v){
        int up = Find(u);
        int vp = Find(v);
        if(up == vp) return;
        if(size[up] < size[vp]){
            parent[up] = vp;
            size[vp] += size[up];
        }
        else{
            parent[vp] = up;
            size[up] += size[vp];
        }
    }

};


class Solution
{
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                int wt = it[1];
                int adjNode = it[0];
                edges.push_back({wt,{i,adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        DSU dsu(V);
        int mstCost=0;
        
        for(auto i: edges){
            
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;
            
            if(dsu.Find(u) != dsu.Find(v)){
                mstCost+=wt;
                dsu.Union(u,v);
            }
        }
        return mstCost;
    }
};
