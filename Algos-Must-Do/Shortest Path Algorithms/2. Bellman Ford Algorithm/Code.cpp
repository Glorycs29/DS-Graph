#include<bits/stdc++.h>
using namespace std;

//bellmanford algo

vector<int> bellmanford(vector<vector<int>>edges,int src,int n){

    vector<int> dist(n,INT_MAX);
    dist[src]=0;

        for(int i=0;i<n-1;i++){
            for(vector<int> edge:edges){
                int cur=edge[0];
                int nbr=edge[1];
                int curDist=edge[2];

                //distance updation

                if(dist[cur] !=INT_MAX && curDist + dist[cur] < dist[nbr]){
                    dist[nbr] = curDist + dist[cur];
                }
            }
        }

        //checking negative edge weight cycle

        for(vector<int> edge:edges){
                int cur=edge[0];
                int nbr=edge[1];
                int curDist=edge[2];

                //distance updation

                if(dist[cur] !=INT_MAX && curDist + dist[cur] < dist[nbr]){
                    dist[nbr] = curDist + dist[cur];
                cout<<"heheheheh..... it contains negative cycle 😁!!";
                return {};
                
                }else break;
        }
        return dist;
    }


int main(){
    int tc; cin>>tc;
    while(tc--){

        int v,n,e,w,u;

        //edge list representation
        cin>>n>>e;
        vector<vector<int>> edges;
        for(int i=0;i<e;i++){
            cin>>u>>v>>w;
            edges.push_back({u,v,w});
        }
        int src; cin>>src;
        
        vector<int> dist = bellmanford(edges,src,n);
        //print the output

        for(int i=0;i<n;i++){
            cout<<"sortest distane to travel from: '"<<src<<"' to: '"<<i<<"' will be: "<<dist[i]<<"\n";
        }

    }
    return 0;
}



// 5 7
// 0 1 -1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 3 1 1
// 0
