//#include <iostream>
//#include <vector>
//#include <set>
//#include <cassert>
//#include <functional>
//#include <queue>
//#include <algorithm>
//#include <iterator>
//#include <climits>
//
//
//
//struct Graph {
// int n; 
//std::vector <std::vector<int>> vertices, reverse_vertices; 
//std::vector <bool> visited;
//std::deque <int> topsort;
//void get_topsort(int v) {
//	visited[v] = true;
//	for (int x : vertices[v])
//	if (!visited[x])
//		get_topsort(x);
//	topsort.push_front(v); 
//	}
//	void get_component(int v, std::vector <int > & component) {
//	visited[v] = true;
//		 component.push_back(v);
//		for (int x : reverse_vertices[v]) 
//			 if (!visited[x])
//			 get_component(x, component);
//		
//	}
//	void add_edge(int a, int b) { 
//		 vertices[a].push_back(b);
//		 reverse_vertices[b].push_back(a);	
//	}
//	std::vector <std::vector <int > > solve() {
//		 topsort.clear();
//		 visited = std::vector <bool>(n, false); // все вершины не помечены
//		 for (int v = 0; v < n; v++)
//			 if (!visited[v])
//			 get_topsort(v);
//		 visited = std::vector <bool>(n, false);
//		 std::vector <std::vector <int > > components;
//		 for (int v : topsort)
//		 if (!visited[v]) {
//			 std::vector <int > component;
//			 get_component(v, component);
//			 components.push_back(component);
//			
//		}
//		 return components;
//		
//	}
//	
//};