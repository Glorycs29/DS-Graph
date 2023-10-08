# Intuition & Approach
<!-- Describe your first thoughts on how to solve this problem. -->
- This problem is asking for check whether the nodes of graph consist of a single component.
- Can be done by DFS/BFS/Union-Find
- The idea is to visit every neighbour node of source node(neighbour: having keys) and so on.
- If any node left unvisited, return false.
- Otherwise true.

# Complexity
- Time complexity: O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    void dfs(int s, vector<vector<int>>& rooms, vector<bool>&vis){
        vis[s]=true;
        for(int i=0; i<rooms[s].size(); i++){
            if(!vis[rooms[s][i]]){
                dfs(rooms[s][i], rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // check for single component problem
        int i=0, n=rooms.size();
        vector<bool> vis(n, false);
        dfs(0, rooms, vis);
        for(i=0; i<n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
```
