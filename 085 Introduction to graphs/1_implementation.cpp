#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph {

    public:
        unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction 0 - represents undirected graph
        // direction 1 - represents directed graph
        adj[u].push_back(v);

        if(direction == 0) {
            adj[v].push_back(u);
        }
    }

    void print() {

        for(auto i : adj) {
            cout << i.first << " -> ";
            for(auto  j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    int n;
    cout << "Enter no of nodes: ";
    cin >> n;

    int m;
    cout << "Enter no of edges: ";
    cin >> m;

    Graph g;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, 0);
    }

    g.print();
    
    return 0;
}

/*
1. create a map and store neighbours of every node in form of list
*/