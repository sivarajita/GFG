class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // code here
        vector<int> rows,cols;
        rows.push_back(0);
        rows.push_back(n+1);
        cols.push_back(0);
        cols.push_back(m+1);
        for(const auto& cell : arr){
            rows.push_back(cell[0]);
            cols.push_back(cell[1]);
            
        }
        sort(rows.begin(),rows.end());
        sort(cols.begin(),cols.end());
        int max_r=0;
        for(size_t i=1;i<rows.size();i++){
            max_r=max(max_r,rows[i]-rows[i-1]-1);
        }
        int max_c=0;
        for(size_t i=1;i<cols.size();i++){
            max_c=max(max_c,cols[i]-cols[i-1]-1);
        }
        return max_r*max_c;
    }
};