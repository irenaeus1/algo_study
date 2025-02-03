#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int N, M, K;
char board[MAX][MAX];
int visited[MAX][MAX][11][2];  // [y][x][벽 부순 횟수][낮/밤]

bool is_valid(int y, int x) {
    return y >= 1 && y <= N && x >= 1 && x <= M;
}

int bfs() {
    queue<tuple<int,int,int,int,int>> q;  // {y, x, 벽 부순 횟수, 낮/밤, 거리}
    q.push({1, 1, 0, 1, 1});  // 시작점, 벽 안부숨, 낮, 거리 1
    visited[1][1][0][1] = 1;
    
    while(!q.empty()) {
        auto [y, x, broken, is_day, dist] = q.front();
        q.pop();
        
        if(y == N && x == M) return dist;
        
        // 현재 위치에서 기다리는 경우 (밤->낮)
        if(!is_day && !visited[y][x][broken][1]) {
            visited[y][x][broken][1] = 1;
            q.push({y, x, broken, 1, dist + 1});
        }
        
        for(int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            int next_day = 1 - is_day;  // 낮/밤 전환
            
            if(!is_valid(ny, nx)) continue;
            
            // 빈 칸으로 이동
            if(board[ny][nx] == '0' && !visited[ny][nx][broken][next_day]) {
                visited[ny][nx][broken][next_day] = 1;
                q.push({ny, nx, broken, next_day, dist + 1});
            }
            
            // 벽을 부수고 이동
            if(board[ny][nx] == '1' && broken < K && is_day && 
               !visited[ny][nx][broken + 1][next_day]) {
                visited[ny][nx][broken + 1][next_day] = 1;
                q.push({ny, nx, broken + 1, next_day, dist + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << bfs() << '\n';
    return 0;
}