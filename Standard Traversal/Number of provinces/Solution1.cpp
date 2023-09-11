class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<bool> visited(v,false);
        int nComp = 0;

        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(v,i,visited,isConnected);
                nComp++;
            }
        } 

        return nComp;
    }

    void dfs(int v, int i, vector<bool> &visited, vector<vector<int>> &isConnected){
        
        visited[i] = true;
        for(int j=0; j<v;j++){

            if(isConnected[i][j] == 1 && !visited[j]){
                dfs(v, j, visited, isConnected);
            }
        }
    }

};
