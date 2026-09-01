class Solution {
  public:
    int palindromicStrings(int n, int k) {
        // code here
        long long MOD = 1e9 + 7;
        long long total = 0;

        for (int len = 1; len <= n; len++) {
            int distinct_needed = (len + 1) / 2;
            
            if (distinct_needed > k) continue;

            long long ways = 1;
            for (int i = 0; i < distinct_needed; i++) {
                ways = (ways * (k - i)) % MOD;
            }
            
            total = (total + ways) % MOD;
        }

        return total;
    }
};