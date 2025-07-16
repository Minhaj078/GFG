#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countNumbers(int n) {
        // Step 1: Generate all primes up to sqrt(n)
        int limit = sqrt(n) + 1;
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * 2; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;

        // Case 1: p^8
        for (int i = 0; i < primes.size(); i++) {
            long long num = 1;
            for (int j = 0; j < 8; j++) {
                num *= primes[i];
                if (num > n) break;
            }
            if (num <= n)
                count++;
        }

        // Case 2: p1^2 * p2^2 (p1 != p2)
        int sz = primes.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                long long val = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                if (val <= n)
                    count++;
                else
                    break;
            }
        }

        return count;
    }
};
