//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        //greedy algo
        //not suitable for negative edge weight cycle
        //for checking of cycle we'll be having a visted vector
        //priority queue for deleting the min node every time,from heap(pq);
        //will maintain distance vector to return.
        
        
        
        vector<int> dist(V,0);
        dist[src]=0;
        vector<bool> vis(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        //push 1st ele. soucre {distance,node}
        pq.push({0,src});
        
        while(!pq.empty()){
            int curDist = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
            
            //if it is visisted then return/continue otherwise
            //mark visit, traverse nbr..same process with nbr...then pq.push({curDist + weight, nbrNode})
            
            if(vis[curNode]) continue;
            
            vis[curNode]  =true;
            dist[curNode] = curDist;
            
            //nbr
            for(auto p:adj[curNode]){
                int nbrNode = p[0];
                int nbrDist = p[1];
                //if visited skip, else push the dist.
                if(vis[nbrNode]) continue;
                //end push
                pq.push({curDist + nbrDist,nbrNode});
            }
            
        }
        return dist;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

// 1
// 4 5
// 0 1 10
// 0 2 6
// 0 3 5
// 1 3 15
// 2 3 4
// 0
// 19



// 1       

// 5 7     
// 0 1 2   
// 0 2 4
// 0 3 6
// 0 4 8
// 1 3 10
// 2 4 12
// 3 4 14
// 1     


