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
//struct vertice
//{
//    vertice()
//    {
//
//    }
//    vertice(int To, int Weight) : to(To), weight(Weight)
//    {
//
//    }
//    int to;
//    int weight;
//};
//
//class ListGraph
//{
//public:
//    ListGraph(int size) : adjacencyLists(size)
//    {
//    }
//
//    //ListGraph(const IGraph& graph) : adjacencyLists(graph.VerticesCount())
//    //{
//    //    for (int i = 0; i < graph.VerticesCount(); i++)
//    //    {
//    //        adjacencyLists[i] = graph.GetNextVertices(i);
//    //    }
//    //}
//
//    ~ListGraph()
//    {
//    }
//
//    void AddEdge(int from, int to, int weight)
//    {
//        assert(0 <= from && from < adjacencyLists.size());
//        assert(0 <= to && to < adjacencyLists.size());
//        adjacencyLists[from].push_back(vertice(to, weight));
//    }
//
//    int VerticesCount()
//    {
//        return (int)adjacencyLists.size();
//    }
//
//    std::vector<vertice> GetNextVertices(int vertex)
//    {
//        assert(0 <= vertex && vertex < adjacencyLists.size());
//        return adjacencyLists[vertex];
//    }
//
//    std::vector<vertice> GetPrevVertices(int vertex)
//    {
//        assert(0 <= vertex && vertex < adjacencyLists.size());
//        std::vector<vertice> prevVertices;
//
//        for (int from = 0; from < adjacencyLists.size(); from++)
//        {
//            for (vertice to : adjacencyLists[from])
//            {
//                if (to.to == vertex)
//                {
//                    prevVertices.push_back(vertice(from, to.weight));
//                }
//            }
//        }
//
//        return prevVertices;
//    }
//
//private:
//    std::vector<std::vector<vertice>> adjacencyLists;
//};
//
//bool Relax(int from, vertice to, std::vector<int>& d, std::vector<int>& p)
//{
//    if (d[to.to] > d[from] + to.weight)
//    {
//        d[to.to] = d[from] + to.weight;
//        p[to.to] = from;
//        return true;
//    }
//    return false;
//}
//void Dijkstra(ListGraph& graph, int vertex, std::vector<int>& d, std::vector<int>& p)
//{
//    d[vertex] = 0;
//    p[vertex] = -1;
//    std::set<std::pair<int, int>> qu;
//    qu.insert(std::pair<int, int>(d[vertex], vertex));
//    while (!qu.empty())
//    {
//        auto current = qu.begin();
//        std::pair<int, int> currentVertex = *current;
//        int old;
//        qu.erase(*qu.begin());
//        for (vertice nextVertex : graph.GetNextVertices(currentVertex.second)) //(vert, weight)
//        {
//            if (d[nextVertex.to] == INT_MAX)
//            {
//                d[nextVertex.to] = d[currentVertex.second] + nextVertex.weight;
//                p[nextVertex.to] = currentVertex.second;
//                qu.insert(std::pair<int, int>(d[nextVertex.to], nextVertex.to));
//            }
//            old = d[nextVertex.to]; //(d[v], v)
//            if (Relax(currentVertex.second, nextVertex, d, p))
//            {
//                std::pair<int, int> next(old, nextVertex.to);
//                qu.erase(*qu.find(next));
//                qu.insert(std::pair<int, int>(d[nextVertex.to], nextVertex.to));
//            }
//
//        }
//    }
//}
//
//
//int main(int argc, const char* argv[]) {
//
//    int a, b;
//    std::cin >> a >> b;
//    int M;
//    std::cin >> M;
//    ListGraph graph(M);
//    for (int i = 0; i < M; ++i)
//    {
//        for (int j = 0; j < M; ++j)
//        {
//            if ((i + 1) % M == 0)
//            {
//                graph.AddEdge(i, j, a);
//            }
//            if ((2 * i + 1) % M == 0)
//            {
//                graph.AddEdge(i, j, b);
//            }
//        }
//    }
//
//    int from, to;
//    std::cin >> from >> to;
//    std::vector<int> d;
//    d.assign(M, INT_MAX);
//    std::vector<int> p;
//    p.assign(M, -1);
//    std::vector<int> k;
//    k.assign(M, 0);
//    Dijkstra(graph, from, d, p);
//    std::cout << d[to];
//    return 0;
//}