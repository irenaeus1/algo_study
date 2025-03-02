//2606번 바이러스

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    int cnt = 0;
    for(int i = 2; i <= N; i++) {
        if(visited[i]) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}