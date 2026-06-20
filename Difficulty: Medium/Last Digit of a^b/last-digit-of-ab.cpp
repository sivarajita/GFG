class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // code here
        // Edge case: if exponent is 0, answer is always 1
        if (b == "0") return 1;
        
        // Edge case: if base is 0, answer is 0 (since b != 0 here)
        if (a == "0") return 0;
        
        // Step 1: Get the last digit of base 'a'
        int base = a[a.length() - 1] - '0';
        
        // Step 2: Find b % 4 using the last one or two digits of string 'b'
        int exp = 0;
        int b_len = b.length();
        
        if (b_len == 1) {
            exp = b[0] - '0';
        } else {
            // Take the last two digits to calculate mod 4
            exp = (b[b_len - 2] - '0') * 10 + (b[b_len - 1] - '0');
        }
        
        int rem = exp % 4;
        // If remainder is 0, it means it's the 4th power in the cycle
        if (rem == 0) rem = 4;
        
        // Step 3: Compute the last digit
        int result = pow(base, rem);
        
        return result % 10;
    }
};