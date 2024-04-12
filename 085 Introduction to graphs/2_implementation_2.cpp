#include<iostream>
using namespace std;

int main()
{   
    int n;
    cout << "Enter no of nodes : ";
    cin >> n;

    int m;
    cout << "Enter no of edges: ";
    cin >> m;

    // SC - O(N^2)

    // 1 base indexing that's why n+1
    int adj[n+1][n+1];

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << endl;

    for(int i=0; i<n+1; i++) {
        for(int j=0; j<n+1; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}