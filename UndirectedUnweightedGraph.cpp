#include "UndirectedUnweightedGraph.h"

UndirectedUnweightedGraph::UndirectedUnweightedGraph(int count)
{
	numberOfVertices = count;
	adjacencyList.resize(numberOfVertices);
}
void UndirectedUnweightedGraph::addEdge(Edge edge)
{
	if (edge.source >= 0 && edge.source < numberOfVertices && edge.destination >= 0 && edge.destination < numberOfVertices) {
	adjacencyList[edge.source].push_back(edge.destination);
	adjacencyList[edge.destination].push_back(edge.source);  
	//This line will be removed to make if it is a directed unweighted graph.
	//Also, there will be another do while loop to check if all nodes are visited in the directed graph
}

}
vector <int> UndirectedUnweightedGraph::BFS(int startVertex, int endVertex) {
	vector <int> path;    //The final path from startVertex to endVertex

	if (numberOfVertices == 0 || endVertex >= numberOfVertices || endVertex < 0 || startVertex >= numberOfVertices || startVertex < 0) {
		cout << "Error! the node doesn't exist" << endl;
		return path;     //Return an empty path to indicate that there is not a path
	}

	vector<bool> visited(numberOfVertices, false);
	int* distance = new int[numberOfVertices];
	int* previous = new int[numberOfVertices];

	queue<int> q;
	q.push(startVertex); 
	visited[startVertex] = true;
	distance[startVertex] = 0;  //distance from start vertex to itself is 
	previous[startVertex] = -1;

	while (q.empty() == false)
	{
		int u = q.front();      //u represents the parent (the source)
		q.pop();

		for (int i = 0; i < adjacencyList[u].size(); i++)
		{
			int v = adjacencyList[u][i];  //v represents children of u (adjacent nodes)
			if (visited[v] == false)
			{
				q.push(v);
				visited[v] = true;
				distance[v] = distance[u] + 1;   //increment the distance from the startvertex to u
				previous[v] = u;                 
			}
		}
	}
	
	if (!visited[endVertex]) {              //it means this node is disconnected from the graph, so it doesn't have any edges
		cout << "There is no path" << endl;
		return path;
	}
	else
	{
		int x = endVertex;     
		path.push_back(endVertex);

		while (x != startVertex)
		{
			path.insert(path.begin(), previous[x]);
			x = previous[x];
		}

		return path;
	}
}