class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        long long low=0;
        long long high=1000;
        int ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long required_strength=(mid*(mid+1)*(2*mid+1))/6;
            if(required_strength<=p){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};
