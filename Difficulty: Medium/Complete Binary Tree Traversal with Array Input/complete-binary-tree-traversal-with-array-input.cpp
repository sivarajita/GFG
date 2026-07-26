class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        int n = arr.size();
        int i = 0;
        int level_size = 1;

        while (i < n) {
            vector<int> current_level;
            
            // Collect elements belonging to the current level
            for (int j = 0; j < level_size && i < n; ++j) {
                current_level.push_back(arr[i]);
                i++;
            }
            
            // Sort elements for this level
            sort(current_level.begin(), current_level.end());
            
            // Add to final result
            ans.push_back(current_level);
            
            // Next level in a complete binary tree has twice the maximum capacity
            level_size *= 2;
        }

        return ans;
    }
};
