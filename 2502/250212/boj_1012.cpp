//1012 유기농 배추

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> graph;
int m, n, k;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    graph[x][y] = 0;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && graph[nx][ny]) {
                q.push({nx, ny});
                graph[nx][ny] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        cin >> m >> n >> k;
        graph = vector<vector<int>>(m, vector<int>(n));
        
        while(k--) {
            int x, y;
            cin >> x >> y;
            graph[x][y] = 1;
        }
        
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
