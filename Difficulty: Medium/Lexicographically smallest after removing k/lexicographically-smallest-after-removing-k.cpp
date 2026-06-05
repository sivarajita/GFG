class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n=s.length();
        if((n&(n-1))==0){
            k=k/2; //n is a power of 2
        }
        else{
            k=k*2; // n is not power of 2
        }
        if(k>=n){
            return "-1";
        }
        string result="";
        for(char ch:s){
            while(!result.empty() && result.back()>ch && k>0){
                result.pop_back();
                k--;
            }
            result.push_back(ch);
        }
        while(k>0 && !result.empty()){
            result.pop_back();
            k--;
        }
        return result;
    }
};