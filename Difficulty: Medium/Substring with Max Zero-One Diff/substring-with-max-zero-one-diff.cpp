class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int max_sum=-1;
        int current_sum=0;
        for(char ch:s){
            int val = (ch=='0') ? 1 : -1;
            current_sum += val;
            if(current_sum>max_sum){
                max_sum=current_sum;
            }
            if(current_sum<0){
                current_sum=0;
            }
        }
        return max_sum;
    }
};