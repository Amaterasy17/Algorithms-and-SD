//#include <iostream>
//#include <vector>
//#include <set>
//#include <cassert>
//#include <functional>
//#include <queue>
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
//
//
//class MatrixGraph: public IGraph
//{
//public:
//    MatrixGraph(int size) : matrix(size)
//    {
//        for (int i = 0; i < size; ++i)
//        {
//            matrix[i] = std::vector<int>(size, 0);
//        }
//    }
//    MatrixGraph(const IGraph& graph) : MatrixGraph(graph.VerticesCount())
//    {
//        for (int i = 0; i < graph.VerticesCount(); i++)
//        {
//            std::vector<int> current_vertices = graph.GetNextVertices(i);
//            while (!current_vertices.empty())
//            {
//                matrix[i][current_vertices.back()] = 1;
//                current_vertices.pop_back();
//            }
//        }
//    }
//
//    ~MatrixGraph()
//    {
//    }
//
//    void AddEdge(int from, int to) override
//    {
//        assert(0 <= from && from < matrix.size());
//        assert(0 <= to && to < matrix.size());
//        matrix[from][to] = 1;
//    }
//
//    int VerticesCount() const override
//    {
//        return (int)matrix.size();
//    }
//
//    std::vector<int> GetNextVertices(int vertex) const override
//    {
//        assert(0 <= vertex && vertex < matrix.size());
//        std::vector<int> res;
//        for (int i = 0; i < matrix.size(); ++i)
//        {
//            if (matrix[vertex][i] == 1)
//            {
//                res.push_back(i);
//            }
//        }
//        return res;
//    }
//
//    std::vector<int> GetPrevVertices(int vertex) const override
//    {
//        assert(0 <= vertex && vertex < matrix.size());
//        std::vector<int> prevVertices;
//        for (int from = 0; from < matrix.size(); ++from)
//        {
//            if (matrix[from][vertex] == 1)
//            {
//                prevVertices.push_back(from);
//            }
//            //for (int to :this->GetNextVertices(from))
//            //{
//            //    if (to == vertex)
//            //    {
//            //        prevVertices.push_back(from);
//            //    }
//            //}
//        }
//
//        return prevVertices;
//    }
//private:
//    std::vector<std::vector<int>> matrix;
//};
//
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
// /*       while (!current_set.empty())
//        {  
//            res.emplace_back(*current_set.end());
//            current_set.erase(current_set.end());
//        }*/
//        for (int i = 0; i < set.size(); ++i)
//        {
//
//            if (set[vertex].find(i) != set[vertex].end())
//            {
//                res.push_back(i);
//            }
//        }
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
//class ArcGraph :public IGraph
//{
//    struct vertice
//    {
//        vertice()
//        {
//
//        }
//        vertice(int From, int To): from(From), to(To)
//        {
//
//        }
//        int from;
//        int to;
//   };
//public:
//    ArcGraph(): vertices(0)
//    {
//
//    }
//
//
//    ArcGraph(const IGraph& graph) : ArcGraph(graph.VerticesCount())
//    {
//        int j = 0;
//        int i;
//        for (i = 0; i < graph.VerticesCount(); i++)
//        {
//            std::vector<int> current_vertices = graph.GetNextVertices(i);
//            while (!current_vertices.empty())
//            {
//                if (i + j == vertices.size() - 1)
//                {
//                    vertices.resize(vertices.size() * 2);
//                }
//                vertices[i+j] = vertice(i, current_vertices.back());
//                current_vertices.pop_back();
//                ++j;
//            }
//            j -= 1;
//        }
//        vertices.resize(i + j);
//    }
//
//    ~ArcGraph()
//    {
//    }
//
//    void AddEdge(int from, int to) override
//    {
//        vertice lol(from, to);
//        vertices.push_back(lol);
//    }
//
//    int VerticesCount() const override
//    {
//        std::set<int> length;
//        for (int i = 0; i < vertices.size(); ++i)
//        {
//            length.insert(vertices[i].from);
//            length.insert(vertices[i].to);
//        }
//
//        return (int)length.size();
//    }
//
//    std::vector<int> GetNextVertices(int vertex) const override
//    {
//        assert(0 <= vertex && vertex < vertices.size());
//        std::vector<int> res;
//        for (int i = 0; i < vertices.size(); ++i)
//        {
//
//            if (vertices[i].from == vertex)
//            {
//                res.push_back(vertices[i].to);
//            }
//        }
//        return res;
//    }
//
//    std::vector<int> GetPrevVertices(int vertex) const override
//    {
//        assert(0 <= vertex && vertex < vertices.size());
//        std::vector<int> prevVertices;
//        for (int i = 0; i < vertices.size(); ++i)
//        {
//
//            if (vertices[i].to == vertex)
//            {
//                prevVertices.push_back(vertices[i].from);
//            }
//        }
//        return prevVertices;
//    }
//    
//
//private:
//    std::vector<vertice> vertices;
//    ArcGraph(int size) : vertices(size)
//    {
//
//    }
//
//};
//
//void BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, std::function<void(int)>& func)
//{
//    std::queue<int> qu;
//    qu.push(vertex);
//    visited[vertex] = true;
//
//    while (!qu.empty())
//    {
//        int currentVertex = qu.front();
//        qu.pop();
//
//        func(currentVertex);
//
//        for (int nextVertex : graph.GetNextVertices(currentVertex))
//        {
//            if (!visited[nextVertex])
//            {
//                visited[nextVertex] = true;
//                qu.push(nextVertex);
//            }
//        }
//    }
//}
//
//void mainBFS(const IGraph& graph, std::function<void(int)> func)
//{
//    std::vector<bool> visited(graph.VerticesCount(), false);
//
//    for (int i = 0; i < graph.VerticesCount(); i++)
//    {
//        if (!visited[i])
//            BFS(graph, i, visited, func);
//    }
//}
//
//void DFS(const IGraph& graph, int vertex, std::vector<bool>& visited, std::function<void(int)>& func)
//{
//    visited[vertex] = true;
//    func(vertex);
//
//    for (int nextVertex : graph.GetNextVertices(vertex))
//    {
//        if (!visited[nextVertex])
//            DFS(graph, nextVertex, visited, func);
//    }
//
//}
//
//void mainDFS(const IGraph& graph, std::function<void(int)> func)
//{
//    std::vector<bool> visited(graph.VerticesCount(), false);
//
//    for (int i = 0; i < graph.VerticesCount(); i++)
//    {
//        if (!visited[i])
//            DFS(graph, i, visited, func);
//    }
//}
//
//void topologicalSortInternal(const IGraph& graph, int vertex, std::vector<bool>& visited, std::deque<int>& sorted)
//{
//    visited[vertex] = true;
//
//    for (int nextVertex : graph.GetNextVertices(vertex))
//    {
//        if (!visited[nextVertex])
//            topologicalSortInternal(graph, nextVertex, visited, sorted);
//    }
//
//    sorted.push_front(vertex);
//}
//
//std::deque<int> topologicalSort(const IGraph& graph)
//{
//    std::deque<int> sorted;
//    std::vector<bool> visited(graph.VerticesCount(), false);
//
//    for (int i = 0; i < graph.VerticesCount(); i++)
//    {
//        if (!visited[i])
//            topologicalSortInternal(graph, i, visited, sorted);
//    }
//
//    return sorted;
//}
//
//
//int main(int argc, const char* argv[]) {
//    ListGraph graph(7);
//    graph.AddEdge(0, 1);
//    graph.AddEdge(0, 5);
//    graph.AddEdge(1, 2);
//    graph.AddEdge(1, 3);
//    graph.AddEdge(1, 5);
//    graph.AddEdge(1, 6);
//    graph.AddEdge(3, 2);
//    graph.AddEdge(3, 4);
//    graph.AddEdge(3, 6);
//    graph.AddEdge(5, 4);
//    graph.AddEdge(5, 6);
//    graph.AddEdge(6, 4);
//
//    mainBFS(graph, [](int vertex) { std::cout << vertex << " "; });
//    std::cout << std::endl;
//
//    mainDFS(graph, [](int vertex) { std::cout << vertex << " "; });
//    std::cout << std::endl;
//
//    for (int vertex : topologicalSort(graph))
//    {
//        std::cout << vertex << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << std::endl;
//
//    
//    ArcGraph arcGraph(graph);
//    SetGraph setGraph(arcGraph);
//    MatrixGraph mGraph(setGraph);
//
//    mainBFS(graph, [](int vertex){ std::cout << vertex << " ";});
//    std::cout << std::endl;
//
//    mainBFS(mGraph, [](int vertex){ std::cout << vertex << " ";});
//    std::cout << std::endl;
//
//
//    return 0;
//}
