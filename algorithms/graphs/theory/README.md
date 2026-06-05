# Graph Algorithms Theory

A graph is a non-linear data structure consisting of vertices (nodes) and edges (connections). Graph algorithms solve problems like traversal, shortest path, connectivity, and cycle detection.

## Graph Representations
1. **Adjacency Matrix**: A 2D array of size $V \times V$ where entry $A[i][j]$ indicates if there is an edge from vertex $i$ to vertex $j$.
2. **Adjacency List**: An array of lists where each list describes the neighbors of a vertex.

## Common Graph Algorithms
- **Breadth-First Search (BFS)**: Level-order traversal of a graph using a queue. Time Complexity: $O(V + E)$.
- **Depth-First Search (DFS)**: Deep traversal of a graph using recursion/stack. Time Complexity: $O(V + E)$.
- **Shortest Path**: Dijkstra's algorithm, Bellman-Ford algorithm, Floyd-Warshall.
- **Minimum Spanning Tree (MST)**: Prim's algorithm, Kruskal's algorithm.
