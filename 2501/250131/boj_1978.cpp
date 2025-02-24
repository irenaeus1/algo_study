#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Prime {
 private:
    vector<int> primes_{2};

 public:
    explicit Prime(int max) {
        for (int i = 3; i <= max; i += 2) {
            bool is_prime = true;
            for (int j = 0; j < primes_.size() && primes_[j] * primes_[j] <= i; j++) {
                if (i % primes_[j] == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                primes_.push_back(i);
            }
        }
    }

    bool IsPrime(int n) const {
        if (n == 1) {
            return false;
        }
        return binary_search(primes_.begin(), primes_.end(), n);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max) {
            max = a[i];
        }
    }

    Prime p(max);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (p.IsPrime(a[i])) {
            count++;
        }
    }
    cout << count;
}



