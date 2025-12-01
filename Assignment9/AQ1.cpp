#include <iostream>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    int adj[100][100];
    int size[100];
    for(int i = 0; i < V; i++){
        size[i] = 0;
        for(int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u][ size[u]++ ] = v;
        adj[v][ size[v]++ ] = u;
    }

    bool visited[100];
    for(int i = 0; i < V; i++) visited[i] = false;

    int count = 0;

    for(int start = 0; start < V; start++){
        if(!visited[start]){
            count++;
            int stack[100];
            int top = -1;
            stack[++top] = start;
            visited[start] = true;

            while(top != -1){
                int node = stack[top--];
                for(int k = 0; k < size[node]; k++){
                    int next = adj[node][k];
                    if(!visited[next]){
                        visited[next] = true;
                        stack[++top] = next;
                    }
                }
            }
        }
    }

    cout << count;
    return 0;
}
