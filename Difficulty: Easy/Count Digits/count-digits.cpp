class Solution {
  public:
    int countDigits(int n) {
        // code here
        int a=0;
        while(n!=0){
            a++;
            n/=10;
        }
        return a;
        
    }
};