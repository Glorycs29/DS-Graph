### Kruskal's Algorithm

Kruskal's algorithm is a greedy algorithm used to find a minimum spanning tree in a connected, weighted graph. It works by selecting edges in ascending order of their weights and adding them to the spanning tree if they don't create a cycle.

**Algorithm Steps**:
1. Sort all the edges in non-decreasing order of their weights.
2. Iterate through the sorted edges:
   - If including the edge doesn't create a cycle in the current spanning tree, add it to the tree.
   - Otherwise, discard the edge.

### Use of Kruskal's Algorithm

- **Minimum Spanning Tree (MST)**: Kruskal's algorithm is used to find the minimum spanning tree of a weighted graph. It is widely applicable in network design, clustering, and many other optimization problems.

### Code Explanation

The provided code implements Kruskal's algorithm to find the minimum spanning tree of a graph using a disjoint-set data structure (DSU).

- The `DSU` class represents a disjoint-set data structure, which is used to keep track of disjoint sets and perform union-find operations efficiently.
- In the `spanningTree` function, the algorithm constructs a list of edges and sorts them by weight. It then iterates through the sorted edges, adding them to the minimum spanning tree if they don't create a cycle using the DSU.

```cpp
class DSU {
    // ... (DSU code here)
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // ... (Kruskal's algorithm code here)
    }
};
