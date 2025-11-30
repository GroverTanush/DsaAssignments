#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

void BFS(int start, const vector<vector<int>> &adj){
    int n = adj.size();
    const int Inf = 1e9;

    vector<int> color(n,WHITE);
    vector<int> dist(n,Inf);
    vector<int> parent(n,-1);

    queue<int> Q;

    color[start] = GRAY;
    dist[start] = 0;
    parent[start] = -1;

    Q.push(start);

    cout << "BFS order: ";

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        cout << u << " ";

        for(int v : adj[u]){
            if(color[v] == WHITE){
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                Q.push(v); 
            }
        }

        color[u] = BLACK;
    }
}

int main(){
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cout << "Enter " << m << " edges(u v) for an undirected graph:\n";
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    BFS(start, adj);

    return 0;
}