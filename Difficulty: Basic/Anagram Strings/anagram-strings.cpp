// User function Template for C++
class Solution {
  public:
    int areAnagram(string S1, string S2) {
        // code here
        if(S1.length()!=S2.length()){
            return 0;
        }
        sort(S1.begin(),S1.end());
        sort(S2.begin(),S2.end());
        return S1==S2;
    }
};