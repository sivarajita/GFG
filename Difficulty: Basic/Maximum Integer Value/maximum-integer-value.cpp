// user function temolate for C++

class Solution {
  public:
    long long int MaximumIntegerValue(string S) {
        // code here
        long long ans = S[0] - '0';
        for(int i=1;i<S.size();i++){
            int digit = S[i] - '0';
        if(digit <= 1 || ans <= 1){
            ans += digit;
        }
        else{
            ans *= digit;
        }
        }
        return ans;
    }
};