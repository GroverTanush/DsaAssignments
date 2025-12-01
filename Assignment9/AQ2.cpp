#include <iostream>
#include <queue>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int grid[100][100];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    int dist[100][100];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = 1e9;

    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>> > pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0,0}});

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    while(!pq.empty()) {
        auto t = pq.top(); 
        pq.pop();
        int cost = t.first;
        int x = t.second.first;
        int y = t.second.second;

        if(cost > dist[x][y]) continue;

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int newCost = cost + grid[nx][ny];
                if(newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }

    cout << dist[m-1][n-1];
    return 0;
}
