#include <iostream>
#include <vector>
using namespace std;

const int WHITE = 0;
const int GRAY  = 1;
const int BLACK = 2;

int Time = 0; 

void DFS_VISIT(int u, const vector<vector<int>> &adj, vector<int> &color, vector<int> &parent, vector<int> &d, vector<int> &f){
    Time = Time + 1;
    d[u] = Time;         
    color[u] = GRAY;     

    cout << u << " ";    

    for(int v : adj[u]) {
        if(color[v] == WHITE) {
            parent[v] = u;        
            DFS_VISIT(v, adj, color, parent, d, f);
        }
    }

    color[u] = BLACK;  
    Time = Time + 1;
    f[u] = Time;       
}

void DFS(const vector<vector<int>> &adj)
{
    int n = adj.size();

    vector<int> color(n, WHITE);
    vector<int> parent(n, -1);
    vector<int> d(n, 0);
    vector<int> f(n, 0);  

    Time = 0;

    cout << "DFS order: ";

    for(int u = 0; u < n; u++) {
        if(color[u] == WHITE) {
            DFS_VISIT(u, adj, color, parent, d, f);
        }
    }
}

int main(){
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cout << "Enter " << m << " edges (u v) for an undirected graph:\n";
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    DFS(adj);

    return 0;
}