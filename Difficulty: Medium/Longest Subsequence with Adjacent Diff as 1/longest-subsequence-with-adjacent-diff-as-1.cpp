class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        unordered_map<int,int> dp;
        int maxLen=0;
        for(int x:arr){
            int lenminus1=dp.count(x-1)?dp[x-1]:0;
            int lenplus1=dp.count(x+1)?dp[x+1]:0;
            dp[x]=1+max(lenminus1,lenplus1);
            maxLen=max(maxLen,dp[x]);
        }
        return maxLen;
    }
};