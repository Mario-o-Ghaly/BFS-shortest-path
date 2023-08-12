#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Edge
{
	int source;
	int destination;
};

class UndirectedUnweightedGraph
{
private:
	int numberOfVertices;
	vector<vector<int>> adjacencyList;
public:
	UndirectedUnweightedGraph(int count);
	void addEdge(Edge edge);
	vector <int> BFS(int startVertex, int endVertex); // Breadth First Search
};