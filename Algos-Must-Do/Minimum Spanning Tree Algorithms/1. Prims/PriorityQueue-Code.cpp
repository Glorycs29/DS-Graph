
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<int> dist(n,INT_MAX);
        vector<bool> vis(n,false);
        dist[0]=0;
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        int mstCost=0;
        
        while(!pq.empty()){
            int cur_node = pq.top().second;
            int cur_dist = pq.top().first;
            pq.pop();
            
            if(vis[cur_node]) continue;
            
            vis[cur_node] = true;
            mstCost += dist[cur_node];
            
            for(vector<int> nbrProp : adj[cur_node]){
                int nbr = nbrProp[0];
                int wt = nbrProp[1];
                
                if(!vis[nbr] && dist[nbr] > wt){
                    dist[nbr] = wt;
                    pq.push({wt,nbr});
                }
            }
        }
        
        return mstCost;
    }
};

