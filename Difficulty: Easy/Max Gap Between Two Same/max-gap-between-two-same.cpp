class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<int> firstIndex(26,-1);
        int maxgap=-1;
        for(int i=0;i<s.length();i++){
            int charidx = s[i]-'a';
            if(firstIndex[charidx]==-1){
                firstIndex[charidx]=i;
            }
            else{
                int currentgap = i - firstIndex[charidx]-1;
                maxgap=max(maxgap,currentgap);
            }
        }
        return maxgap;
    }
};