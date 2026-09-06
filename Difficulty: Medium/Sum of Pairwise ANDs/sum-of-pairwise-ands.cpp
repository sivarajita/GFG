class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        long long total_sum=0;
        for(int bit=0;bit<32;bit++){
            long long count=0;
            for(int num:arr){
                if(num&(1<<bit)){
                    count++;
                }
            }
            long long pairs=(count*(count-1))/2;
            total_sum+=pairs*(1LL<<bit);
            
        }
        return total_sum;
    }
};