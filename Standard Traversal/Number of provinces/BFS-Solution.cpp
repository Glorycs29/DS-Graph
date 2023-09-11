class Solution {
public:
    void bfs(int node, vector<bool> &visited, vector<vector<int>>& isConnected){
        queue<int> q;
        q.push(node);
        visited[node]=true;

        while(!q.empty()){
            node = q.front();
            q.pop();

            for(int i=0; i<isConnected.size(); i++){

                if(isConnected[node][i] && !visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int nComp=0;
        vector<bool> visited(v,false);

        for(int i=0; i<v; i++){
            if(!visited[i]){
                bfs(i,visited,isConnected);
                nComp++;
            }
        }
        return nComp;
    }
};
