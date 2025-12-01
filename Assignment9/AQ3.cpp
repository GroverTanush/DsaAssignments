#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K, E;
    cin >> N >> K >> E;

    int u[200], v[200], w[200];
    for(int i = 0; i < E; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    int adjU[200][200], adjV[200][200], adjW[200][200];
    int size[200];
    for(int i = 1; i <= N; i++) {
        size[i] = 0;
        for(int j = 0; j < N; j++) {
            adjU[i][j] = adjV[i][j] = adjW[i][j] = 0;
        }
    }

    for(int i = 0; i < E; i++) {
        int x = u[i], y = v[i], wt = w[i];
        adjV[x][ size[x] ] = y;
        adjW[x][ size[x] ] = wt;
        size[x]++;
    }

    int dist[200];
    for(int i = 1; i <= N; i++) dist[i] = 1e9;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[K] = 0;
    pq.push({0, K});

    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int cost = t.first;
        int node = t.second;

        if(cost > dist[node]) continue;

        for(int i = 0; i < size[node]; i++) {
            int nxt = adjV[node][i];
            int wt = adjW[node][i];

            if(cost + wt < dist[nxt]) {
                dist[nxt] = cost + wt;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(dist[i] == 1e9) {
            cout << -1;
            return 0;
        }
        if(dist[i] > ans) ans = dist[i];
    }

    cout << ans;
    return 0;
}
