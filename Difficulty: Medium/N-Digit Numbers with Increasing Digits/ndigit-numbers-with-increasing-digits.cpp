class Solution {
public:
    void backtrack(int n, int current_num, int last_digit, vector<int>& result) {
        // Base Case: If the number has reached n digits
        if (n == 0) {
            result.push_back(current_num);
            return;
        }

        // Try all possible next digits that are strictly greater than last_digit
        for (int next_digit = last_digit + 1; next_digit <= 9; next_digit++) {
            // Append the next digit to the current number
            int new_num = current_num * 10 + next_digit;
            
            // Recurse with length reduced by 1, and update the last_digit
            backtrack(n - 1, new_num, next_digit, result);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> result;
        
        // Edge Case: If n == 1, 0 is considered a valid single-digit increasing number
        if (n == 1) {
            result.push_back(0);
        }
        
        // Start backtracking. The first digit can range from 1 to 9.
        // We pass 0 as the initial 'last_digit' so the loop naturally starts picking from 1.
        backtrack(n, 0, 0, result);
        
        return result;
    }
};