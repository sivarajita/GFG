class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n<=1)
        return 0;
        int dp0=0;
        int dp1=0;
        for(int i=1;i<n;i++){
            int next_dp0=max(dp0,dp1+abs(arr[i-1]-1));
            int next_dp1=max(dp0+abs(arr[i]-1),dp1+abs(arr[i]-arr[i-1]));
            dp0=next_dp0;
            dp1=next_dp1;
        }
        return max(dp0,dp1);
    }
};