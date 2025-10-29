class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int result = 0;
        for(char digit : b){
            result = result * 2 + (digit - '0');
        }
        return result;
    }
};