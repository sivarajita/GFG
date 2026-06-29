class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size();
        int m=b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(i,m);j++){
                int exclude=dp[i-1][j];
                int include=dp[i-1][j-1]+a[i-1]*b[j-1];
                dp[i][j]=max(exclude,include);
            }
        }
        return dp[n][m];
    }
};
