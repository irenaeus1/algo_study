#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

long long find_nth_number(int K, int N, vector<long long>& primes) {
    priority_queue<long long, vector<long long>, greater<>> pq;
    unordered_set<long long> used;
    
    // 처음에 모든 소수를 우선순위 큐에 넣음
    for(int i = 0; i < K; i++) {
        pq.push(primes[i]);
        used.insert(primes[i]);
    }

    long long current;
    long long max_num = primes[K-1];
    for(int i = 0; i < N; i++) {
        current = pq.top();
        pq.pop();
        for(int j = 0; j < K; j++) {
            long long next = current * primes[j];
            if(next >= (1LL << 31)) continue;
            if(used.find(next) != used.end()) continue;
            if(pq.size() >= N-i && max_num < next) continue;
            pq.push(next);
            primes.push_back(next);
            used.insert(next);
            max_num = max(max_num, next);
        }
    }

    return current;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K, N;
    cin >> K >> N;
    
    vector<long long> primes(K);
    for(int i = 0; i < K; i++) {
        cin >> primes[i];
    }
    sort(primes.begin(), primes.end());
    cout << find_nth_number(K, N, primes) << '\n';
    
    return 0;
}