class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        long long MOD=1e9+7;
        long long low=0,high=0;
        for(int x:arr){
            high=max(high,(long long)x);
        }
        long long threshold=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long count=0;
            for(int x:arr){
                if(x>=mid){
                    count+=(x-mid+1);
                }
            }
            if(count>=k){
                threshold=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        long long ans=0;
        long long tickets_sold=0;
        for(long long x:arr){
            if(x>threshold){
                long long count=x-threshold;
                tickets_sold+=count;
                long long sum=(count*(x+threshold+1))/2;
                ans=(ans+sum)%MOD;
            }
        }
        if(tickets_sold<k){
            long long remaining=k-tickets_sold;
            ans=(ans+(remaining*threshold)%MOD)%MOD;
        }
        return ans;
    }
};