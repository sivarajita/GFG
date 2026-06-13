class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    // Function to find modular inverse of a number using Fermat's Little Theorem
    long long modInverse(long long n, long long mod) {
        return power(n, mod - 2, mod);
    }

    int computeValue(int n) {
        long long mod = 1e9 + 7;
        
        // We need to calculate (2n)! / (n! * n!) % mod
        long long numerator = 1;
        for (int i = 1; i <= 2 * n; i++) {
            numerator = (numerator * i) % mod;
        }
        
        long long denominator = 1;
        for (int i = 1; i <= n; i++) {
            denominator = (denominator * i) % mod;
        }
        
        // (n! * n!) % mod
        denominator = (denominator * denominator) % mod;
        
        // Final calculation: numerator * modInverse(denominator) % mod
        long long ans = (numerator * modInverse(denominator, mod)) % mod;
        
        return ans;
    }
};