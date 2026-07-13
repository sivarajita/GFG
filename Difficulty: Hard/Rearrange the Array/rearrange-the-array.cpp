class Solution {
  public:
    int minOperations(vector<int> &b) {
        // code here
        int n = b.size();
        vector<bool> visited(n, false);
        unordered_map<int, int> max_prime_powers;
        long long MOD = 1e9 + 7;

        // Step 1: Find all disjoint cycle lengths
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int curr = i;
            int cycle_length = 0;

            while (!visited[curr]) {
                visited[curr] = true;
                // b[curr] - 1 handles 1-based indexing conversion to 0-based
                curr = b[curr] - 1; 
                cycle_length++;
            }

            // Step 2: Extract prime factors and update their max powers
            int temp = cycle_length;
            for (int p = 2; p * p <= temp; p++) {
                if (temp % p == 0) {
                    int count = 0;
                    while (temp % p == 0) {
                        count++;
                        temp /= p;
                    }
                    max_prime_powers[p] = max(max_prime_powers[p], count);
                }
            }
            if (temp > 1) { // If remaining temp is a prime
                max_prime_powers[temp] = max(max_prime_powers[temp], 1);
            }
        }

        // Step 3: Compute the LCM modulo 10^9 + 7
        long long ans = 1;
        for (auto const& [prime, power] : max_prime_powers) {
            long long prime_pow = 1;
            for (int i = 0; i < power; i++) {
                prime_pow = (prime_pow * prime) % MOD;
            }
            ans = (ans * prime_pow) % MOD;
        }

        return ans;
    }
};