class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        int n=s.size();
        int maxLen=0;
        for(int i=0;i<n;i++){
            vector<int> hash(256,0);
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1){
                    break;
                }
                hash[s[j]]=1;
                int len=j-i+1;
                maxLen=max(maxLen,len);
                
            }
        }
        return maxLen;
    }
};