// 25_BellmanFordAlgorithm_SSSP.cpp



// Steps

// 1 - Init dist[vertices] = INT_MAX, dist[src] = 0

// 2 - Relax all edges, V-1 times (iterations) [Most Important]
// for(i -> V-1 times) {
// 	for each edge (u->v) {
// 		if dist[v] > dist[u] + weight[u->v]
// 		then dist[v] = dist[u] + weight[u->v]
// 	}
// }


// 3 - Negative Weight Cycle Detection


// Why V-1 iterations ???
// Suppose we have V vertices 
// so the largest path may have V-1 Edges
// and the smallest path may have only 1 edge