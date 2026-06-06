class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        long long cells=1LL*n*m;
        long long totalplaces=cells*(cells-1);
        long  long attackingplaces=4LL*(1LL*(n-1)*max(0,m-2)+1LL*(n-2)*max(0,m-1));
        return totalplaces-attackingplaces;
    }
};