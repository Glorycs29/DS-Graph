class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // We'll use topological sort to solve this question
        // but topological only works in DAG (no cycles)
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> dis(n,0);
        vector<int> adj[n];
        // we will make a adjacancy list by reversing the edges between two nodes.
        for(int i=0; i<n; i++){
            for(auto &x: graph[i]){
                adj[x].push_back(i);
                dis[i]++;
            }
        }

        // first of all we store all elements whose out-degree is 0 in a queue that is dist[i]=0
        queue<int> q;
        for(int i=0; i<n; i++){
            if(dis[i]==0){
                q.push(i);
            }
        }

        // Simpy BFS will be run after decrementing the dist of adjacancy vertices we will check if dist[i]=0, then we simply push in the queue 
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            // all the node whose dist become 0 at some point of time will be stored in ans vector.
            for(auto x: adj[node]){
                dis[x]--;
                if(dis[x]==0){
                    q.push(x);
                }
            }
        }

        // sort and simply return ans vector   
        sort(ans.begin(), ans.end());
        return ans; 
    }
};
