class Solution {
public:
    bool kSubstr(string &s, int k) {
        int n = s.length();
        
        // Base Case: If the string cannot be evenly divided into k-length blocks
        if (n % k != 0) return false;
        
        // Map to store the frequency of each unique k-length substring
        unordered_map<string, int> blockFreq;
        
        // Extract and count each block
        for (int i = 0; i < n; i += k) {
            string block = s.substr(i, k);
            blockFreq[block]++;
        }
        
        // Case 1: All blocks are already identical
        if (blockFreq.size() == 1) {
            return true;
        }
        
        // Case 2: There are exactly two distinct blocks
        if (blockFreq.size() == 2) {
            // Check if at least one of the blocks occurs exactly once
            for (auto const& [block, count] : blockFreq) {
                if (count == 1) {
                    return true;
                }
            }
        }
        
        // Case 3: More than 2 unique blocks, or 2 blocks both repeating multiple times
        return false;
    }
};