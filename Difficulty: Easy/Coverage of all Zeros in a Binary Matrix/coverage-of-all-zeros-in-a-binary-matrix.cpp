class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        // code here
        int rows=mat.size();
        int cols=mat[0].size();
        int totalcoverage=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0){
                    for(int k=i-1;k>=0;k--){
                        if(mat[k][j]==1){
                            totalcoverage++;
                            break;
                        }
                    }
                    for(int k=i+1;k<rows;k++){
                        if(mat[k][j]==1){
                            totalcoverage++;
                            break;
                        }
                    }
                    for(int k=j-1;k>=0;k--){
                        if(mat[i][k]==1){
                            totalcoverage++;
                            break;
                        }
                    }
                    for(int k=j+1;k<cols;k++){
                        if(mat[i][k]==1){
                            totalcoverage++;
                            break;
                        }
                    }
                }
            }
        }
        return totalcoverage;
    }
};
