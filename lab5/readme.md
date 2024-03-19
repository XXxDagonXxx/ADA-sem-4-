# Problem 1: Prim's Algorithm

The provided C++ implementation offers a solution to find the MST using Prim's Algorithm. It selects the minimum-weight edge at each step to grow the spanning tree until all vertices are included, ensuring a connected and acyclic tree.Prim's Algorithm is a greedy algorithm that efficiently finds the minimum-weight spanning tree for a connected, undirected graph.

**Pseudocode:**
![prims](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/6215de13-4335-4c46-b7f5-af858c061737)


**Time Complexity:**
The time complexity of the algorithm is O(V^2) with an adjacency matrix representation and O((V + E) log V) with an adjacency list representation, where "V" is the number of vertices and "E" is the number of edges.

**Use Cases:**
1. Network Design:

Useful in designing efficient communication networks where connecting all locations with minimum total cable length is crucial.

2. Circuit Design:

Applied in designing circuits to connect all components with the minimum total wire length.

3. Transportation Networks:

Used in optimizing transportation routes to minimize the overall cost of constructing roads or railways.

# Problem 2: Single Source Shortest Path Algorithm

Single-Source Shortest Path (SSSP) algorithm, specifically Dijkstra's Algorithm, and provides a C++ implementation to find the shortest paths from a source vertex to all other vertices in a weighted graph.The provided C++ implementation offers a solution using Dijkstra's Algorithm to find the shortest paths from a specified source vertex. Dijkstra's Algorithm is a greedy algorithm that iteratively selects the vertex with the smallest tentative distance from the source.

**Pseudocode:**
![sssp](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/8ca793e2-d307-4407-9dd9-11e7910e1ab0)


**Time Complexity:**

The time complexity of Dijkstra's Algorithm is O((V + E) log V) with a binary heap or Fibonacci heap implementation, where "V" is the number of vertices and "E" is the number of edges.

**Use Cases:**

1. Routing Algorithms:

Applied in network routing protocols to find the shortest paths between routers.

2. Transportation Networks:

Useful in optimizing transportation routes to minimize travel time.

3. Resource Allocation:

Applicable in scenarios where resources need to be allocated efficiently based on distance.
