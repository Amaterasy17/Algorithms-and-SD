//#include <iostream>
//#include <vector>
//#include <set>
//#include <cassert>
//#include <functional>
//#include <queue>
//#include <algorithm>
//#include <iterator>
//
//struct IGraph {
//    virtual ~IGraph() {}
//
//    // Добавление ребра от from к to.
//    virtual void AddEdge(int from, int to) = 0;
//
//    virtual int VerticesCount() const = 0;
//
//    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
//    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
//};
//
//class ListGraph : public IGraph
//{
//public:
//    ListGraph(int size) : adjacencyLists(size)
//    {
//    }
//
//    ListGraph(const IGraph& graph) : adjacencyLists(graph.VerticesCount())
//    {
//        for (int i = 0; i < graph.VerticesCount(); i++)
//        {
//            adjacencyLists[i] = graph.GetNextVertices(i);
//        }
//    }
//
//    ~ListGraph()
//    {
//    }
//
//    void AddEdge(int from, int to) override
//    {
//        assert(0 <= from && from < adjacencyLists.size());
//        assert(0 <= to && to < adjacencyLists.size());
//        adjacencyLists[from].push_back(to);
//    }
//
//    int VerticesCount() const override
//    {
//        return (int)adjacencyLists.size();
//    }
//
//    std::vector<int> GetNextVertices(int vertex) const override
//    {
//        assert(0 <= vertex && vertex < adjacencyLists.size());
//        return adjacencyLists[vertex];
//    }
//
//    std::vector<int> GetPrevVertices(int vertex) const override
//    {
//        assert(0 <= vertex && vertex < adjacencyLists.size());
//        std::vector<int> prevVertices;
//
//        for (int from = 0; from < adjacencyLists.size(); from++)
//        {
//            for (int to : adjacencyLists[from])
//            {
//                if (to == vertex)
//                {
//                    prevVertices.push_back(from);
//                }
//            }
//        }
//
//        return prevVertices;
//    }
//
//private:
//    std::vector<std::vector<int>> adjacencyLists;
//};
//
//class MatrixGraph : public IGraph
//    {
//    public:
//        MatrixGraph(int size) : matrix(size)
//        {
//            for (int i = 0; i < size; ++i)
//            {
//                matrix[i] = std::vector<int>(size, 0);
//            }
//        }
//        MatrixGraph(const IGraph& graph) : MatrixGraph(graph.VerticesCount())
//        {
//            for (int i = 0; i < graph.VerticesCount(); i++)
//            {
//                std::vector<int> current_vertices = graph.GetNextVertices(i);
//                while (!current_vertices.empty())
//                {
//                    matrix[i][current_vertices.back()] = 1;
//                    current_vertices.pop_back();
//                }
//            }
//        }
//    
//        ~MatrixGraph()
//        {
//        }
//    
//        void AddEdge(int from, int to) override
//        {
//            assert(0 <= from && from < matrix.size());
//            assert(0 <= to && to < matrix.size());
//            matrix[from][to] = 1;
//        }
//    
//        int VerticesCount() const override
//        {
//            return (int)matrix.size();
//        }
//    
//        std::vector<int> GetNextVertices(int vertex) const override
//        {
//            assert(0 <= vertex && vertex < matrix.size());
//            std::vector<int> res;
//            for (int i = 0; i < matrix.size(); ++i)
//            {
//                if (matrix[vertex][i] == 1)
//                {
//                    res.push_back(i);
//                }
//            }
//            return res;
//        }
//    
//        std::vector<int> GetPrevVertices(int vertex) const override
//        {
//            assert(0 <= vertex && vertex < matrix.size());
//            std::vector<int> prevVertices;
//            for (int from = 0; from < matrix.size(); ++from)
//            {
//                if (matrix[from][vertex] == 1)
//                {
//                    prevVertices.push_back(from);
//                }
//                //for (int to :this->GetNextVertices(from))
//                //{
//                //    if (to == vertex)
//                //    {
//                //        prevVertices.push_back(from);
//                //    }
//                //}
//            }
//    
//            return prevVertices;
//        }
//    private:
//        std::vector<std::vector<int>> matrix;
//    };
//
//class SetGraph : public IGraph
//{
//public:
//    SetGraph(int size) : set(size)
//    {
//
//    }
//    SetGraph(const IGraph& graph) : set(graph.VerticesCount())
//    {
//        for (int i = 0; i < graph.VerticesCount(); i++)
//        {
//            std::vector<int> current_vertices = graph.GetNextVertices(i);
//            while (!current_vertices.empty())
//            {
//                set[i].insert(current_vertices.back());
//                current_vertices.pop_back();
//            }
//        }
//    }
//
//    ~SetGraph()
//    {
//    }
//
//    void AddEdge(int from, int to) override
//    {
//        assert(0 <= from && from < set.size());
//        assert(0 <= to && to < set.size());
//        set[from].insert(to);
//    }
//
//    int VerticesCount() const override
//    {
//        return (int)set.size();
//    }
//
//    std::vector<int> GetNextVertices(int vertex) const override
//    {
//        assert(0 <= vertex && vertex < set.size());
//        std::vector<int> res;
//        std::set<int> current_set = set[vertex];
//        std::copy(current_set.begin(), current_set.end(), std::inserter(res, res.end()));
//        /*       while (!current_set.empty())
//               {
//                   res.emplace_back(*current_set.end());
//                   current_set.erase(current_set.end());
//               }*/
//        //for (int i = 0; i < set.size(); ++i)
//        //{
//
//        //    if (set[vertex].find(i) != set[vertex].end())
//        //    {
//        //        res.push_back(i);
//        //    }
//        //}
//        return res;
//    }
//
//    std::vector<int> GetPrevVertices(int vertex) const override
//    {
//        assert(0 <= vertex && vertex < set.size());
//        std::vector<int> prevVertices;
//        for (int from = 0; from < set.size(); ++from)
//        {
//            auto mem = set[from].find(from);
//            if (set[from].find(from) != set[vertex].end())
//            {
//                prevVertices.push_back(from);
//            }
//        }
//
//        return prevVertices;
//    }
//
//private:
//    std::vector<std::set<int>> set;
//};
//
//void BFS(const IGraph& graph, int vertex,  std::vector<int>& d, std::vector<int>& p, std::vector<int>& k)
//{
//    std::queue<int> qu;
//    qu.push(vertex);
//    d[vertex] = 0;
//    p[vertex] = -1;
//    k[vertex] = 1;
//    while (!qu.empty())
//    {
//        int currentVertex = qu.front();
//        qu.pop();
//        for (int nextVertex : graph.GetNextVertices(currentVertex))
//        {
//            if (d[nextVertex] == d[currentVertex] + 1)
//            {
//                k[nextVertex] += k[currentVertex];
//            }
//            if (d[nextVertex] > d[currentVertex] + 1)
//            {
//                d[nextVertex] = d[currentVertex] + 1;
//                p[nextVertex] = currentVertex;
//                k[nextVertex] = k[currentVertex];
//                qu.push(nextVertex);
//            }
//
//        }
//    }
//}
//
//int main(int argc, const char* argv[]) {
// 
//
//    int v, n;
//    std::cin >> v;
//    std::cin >> n;
//    SetGraph graph(v);
//    int u, w;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> u >> w;
//        graph.AddEdge(u, w);
//        graph.AddEdge(w, u);
//    }
//    int from, to;
//    std::cin >> from >> to;
//    std::vector<int> d;
//    d.assign(v, 1000000);
//    std::vector<int> p;
//    p.assign(v, -1);
//    std::vector<int> k;
//    k.assign(v, 0);
//    BFS(graph, from, d, p, k);
//    std::cout << k[to];
//    return 0;
//}
