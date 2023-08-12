#include "UndirectedUnweightedGraph.h"

void construct_graph(UndirectedUnweightedGraph &graph, int n){
    int edgs, x, y;
        cout<<"Vertices are numbered from 0 till "<<n-1<<"\nPlease enter the number of edges: "; cin>>edgs;
        for(int i=0; i<edgs; ++i){
            cout<<"Enter vertices of edge number "<<i+1<<" separated by space: ";
            cin>>x>>y;
            graph.addEdge({x,y});
        }
}

int main() {
    string input;
    while(true){
        cout<<"Enter M if you prefer to enter the graph manually\nOr enter E if you want to try the implemented examples: ";
        cin>>input;
        if(input != "M" && input != "E"){
            cout<<"Wrong input. Please try again: "; continue;
        }

        else break;
    }

    int n1, n2;
    cout << "Graph 1:" << endl;
    if(input == "M"){
        cout<<"Enter the number of vertices: "; cin>>n1;
    }
    else n1 = 7;

    UndirectedUnweightedGraph graph(n1);
    if(input == "M"){
        construct_graph(graph, n1);
    }
    else{
        graph.addEdge({ 0, 6 });
        graph.addEdge({ 0, 5 });
        graph.addEdge({ 5, 1 });
        graph.addEdge({ 6, 2 });
        graph.addEdge({ 1, 6 });
        graph.addEdge({ 1, 4 });
        graph.addEdge({ 1, 2 });
        graph.addEdge({ 3, 2 });
        graph.addEdge({ 4, 3 });
    }

    int s, d;
    cout << "Enter the source: ";
    cin >> s;
    cout << "Enter the destination: ";
    cin >> d;
    cout << "The shortest path from " << s << " to " << d << " is:  ";
    vector <int> path = graph.BFS(s, d);
    if (path.size() > 1) {
        vector <int>::iterator iter;
        for (iter = path.begin(); iter != path.end(); iter++) {
            cout << *iter << "  ";
        }
    }

    cout << endl << endl << "Graph 2:" << endl;
    if(input == "M"){
        cout<<"Enter the number of vertices: "; cin>>n2;
    }
    else n2 = 9;

    UndirectedUnweightedGraph graph2(n2);
    if(input == "M"){
        construct_graph(graph2, n2);
    }
    else{
        graph2.addEdge({ 7, 3 });
        graph2.addEdge({ 7, 0 });
        graph2.addEdge({ 0, 1 });
        graph2.addEdge({ 0, 6 });
        graph2.addEdge({ 1, 6 });
        graph2.addEdge({ 1, 5 });
        graph2.addEdge({ 1, 3 });
        graph2.addEdge({ 4, 3 });
        graph2.addEdge({ 4, 2 });
        graph2.addEdge({ 2, 5 });
    }
    cout << "Enter the source: ";
    cin >> s;
    cout << "Enter the destination: ";
    cin >> d;
    cout << "The shortest path from " << s << " to " << d << " is:  ";
    vector <int> path2 = graph2.BFS(s, d);
    if (path2.size() > 1) {
        vector <int>::iterator iter2;
        for (iter2 = path2.begin(); iter2 != path2.end(); iter2++) {
            cout << *iter2 << "  ";
        }
    }

    system("pause"); // This is Windows-specific

    return 0;
}
