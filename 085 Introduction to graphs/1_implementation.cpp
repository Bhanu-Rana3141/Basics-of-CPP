#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Graph {

    public:
        unordered_map<int, vector<int>> adj;

    void addEdge(int u, int v, bool direction) {

        adj[u].push_back(v);
        if(!direction) {
            adj[v].push_back(u);
        }
    }    

    void print() {

        for(auto i : adj) {
            cout << i.first << " -> ";
            for(auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;   

    Graph g;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        // if 0 -> undirected or if 1 -> directed GRAPH
        g.addEdge(u, v, 0);
    }    

    cout << endl;
    g.print();

    return 0;
}