class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        
                if (x == 0) return true;

                vector<long long> seq;
                seq.push_back(s);
                long long current_sum = s;

                // Step 1: Generate elements until val > x or array ends
                for (int a : arr) {
                    long long val = current_sum + a;
                    seq.push_back(val);
                    current_sum += val;
                    if (val > x) break;
                }

                // Step 2: Traverse backwards and pick greedily
                for (int i = seq.size() - 1; i >= 0; --i) {
                    if (x >= seq[i]) {
                        x -= seq[i];
                    }
                    if (x == 0) return true;
                }

                return x == 0;
    }
};