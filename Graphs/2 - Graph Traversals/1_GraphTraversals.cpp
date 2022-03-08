// 1_GraphTraversals.cpp
// Link - https://ide.codingblocks.com/s/657936

// There are two ways of traversing a Graph 
// 1 - BFS (Iterative Way)
// 2 - DFS (Recursive Way)

// BFS
// 1 - Vertex based technique.
// 2 - It uses a Queue data structure. 
// 3 - In BFS, one vertex is selected at a time when it is visited and marked then its adjacent are visited and stored in the queue. 
// 4 - It is slower than DFS. 
// 5 - Used to find SSSP in an Unweigted Graph, 
//     because in BFS we reach to the dest in exploring min number of edges.
// TC: O(V+E) using adjecency list, O(VE) using Adjacency Matrix
// SC: O(V) for storing Vertices in Queue.

// DFS
// 1 - It uses edge based technique. 
// 2- It uses the Stack data structure, 
// 3 - It performs two stages, first visited vertices are pushed into stack and 
//    second if there is no vertices then visited vertices are popped. 
// 4 - DFS is Faster.
// 5 - DFS is more suitable for game or puzzle problems. 
//     We make a decision, then explore all paths through this decision. 
//     And if this decision leads to win situation, we stop.
// TC: O(V+E) using adjecency list, O(VE) using Adjacency Matrix
// SC: O(V) to Call Stack space.