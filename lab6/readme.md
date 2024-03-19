## Program 1: Multistage Graph

The algorithm solves the shortest path problem in a multistage graph, where the graph is organized into several stages, and the goal is to find the minimum-cost path from the starting node to the ending node.

**Pseudocode:**
![multistage](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/40fa0021-9c80-453d-8847-411e5c049dfd)



**Time Complexity**

The time complexity of the Multistage Graph algorithm is O(V^2), where V is the number of vertices in the graph

## Program 2: Cycle Detection:

__Aim:__

The aim of this program is to implement a cycle detection algorithm for an undirected graph using the union-find (disjoint-set) data structure.
__Problem Statement:__

Given an undirected graph represented by its edges, the task is to determine whether the graph contains a cycle.

__Algorithm:__

1.	Initialize a disjoint-set data structure, where each vertex is initially in its own set.
2.	Iterate through each edge in the graph:
   
  •	Find the roots of the endpoints of the current edge using the find function.

  •	If the roots are the same, indicating that the endpoints belong to the same set, a cycle is detected. Return true.
  
  •	Otherwise, merge the sets of the endpoints using the unionSets function.
3.	If no cycles are detected after checking all edges, return false.

__Time Complexity:__

  •	 The time complexity of the find operation in the disjoint-set data structure is O(log n), where n is the number of vertices.
  
  •	The time complexity of the unionSets operation depends on the implementation, but it is typically O(log n)
  
  •	The overall time complexity of the cycle detection algorithm is O(E * α(V)), where E is the number of edges and V is the number of vertices, and α(V) is the 
    inverse Ackermann function, which grows extremely slowly and can be considered almost constant for practical purposes. Therefore, the algorithm is 
    effectively linear in the number of edges.


## Program 3: kruskals algorithm

Kruskal's algorithm is a greedy algorithm that finds a minimum spanning tree for a connected, undirected graph. It works by sorting the edges in non-decreasing order of weight and adding each edge to the MST as long as it does not form a cycle. The Disjoint-Set data structure is used to efficiently check whether adding an edge creates a cycle

**Pseudocode:**
![kruskal](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/6482cdd3-1656-439d-b317-3cd94d604373)


**Time Complexity**

The time complexity of Kruskal's algorithm is dominated by the sorting step, which has a time complexity of O(E log E), where E is the number of edges. The Union-Find operations (finding and merging) take nearly constant time on average. Overall, the time complexity of the entire algorithm is O(E log E).
