#include <iostream>
using namespace std;

int grid[100][100];
bool visited[100][100];
int m, n;

void dfs(int x, int y) {
    visited[x][y] = true;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx >= 0 && ny >= 0 && nx < m && ny < n) {
            if(grid[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> m >> n;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = false;

    int count = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                count++;
                dfs(i, j);
            }
        }
    }

    cout << count;
    return 0;
}
