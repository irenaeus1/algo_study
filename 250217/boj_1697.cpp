//1697 숨바꼭질

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> dist(100001, -1);
    queue<int> q;

    dist[n] = 0;
    q.push(n);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if(now == k) {
            cout << dist[now];
            return 0;
        }

        if(now - 1 >= 0 && dist[now - 1] == -1) {
            dist[now - 1] = dist[now] + 1;
            q.push(now - 1);
        }
        if(now + 1 <= 100000 && dist[now + 1] == -1) {
            dist[now + 1] = dist[now] + 1;
            q.push(now + 1);
        }
        if(now * 2 <= 100000 && dist[now * 2] == -1) {
            dist[now * 2] = dist[now] + 1;
            q.push(now * 2);
        }
    }

    return 0;
}
