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

class Solution {
public:
    int findCircleNum(vector<vector<int>>& group) {
        int n = group.size();
        int nComp = 0;

        DSU dsu(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(group[i][j]){
                    dsu.Union(i,j);
                } 
            }
        }

        for(int i=0; i<n; i++){
            nComp += dsu.Find(i)==i;
        }
        return nComp;

    }
};
