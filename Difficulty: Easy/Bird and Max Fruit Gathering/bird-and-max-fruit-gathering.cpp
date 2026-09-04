class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n=arr.size();
        if(m>=n){
            long long total=0;
            for(int val:arr)
            total+=val;
            return total;
        }
        long long curr_sum=0;
        for(int i=0;i<m;i++){
            curr_sum+=arr[i];
        }
        long long max_sum=curr_sum;
        for(int i=1;i<n;i++){
            curr_sum+=arr[(i+m-1)%n]-arr[i-1];
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum;
    }
};