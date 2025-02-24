//7576 토마토

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    queue<pair<int, int>> q;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int day = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1) q.push({i, j});
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (v[nx][ny] == 0) {
                v[nx][ny] = 1;
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
                day = max(day, visited[nx][ny]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << day;
    return 0;
}
