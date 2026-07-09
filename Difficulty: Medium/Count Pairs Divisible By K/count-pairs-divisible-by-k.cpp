class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
     vector<long long> remFreq(k,0);
     for(int num:arr){
         int rem=((num%k)+k)%k;
         remFreq[rem]++;
     }
     long long totalpairs=0;
     totalpairs+=(remFreq[0]*(remFreq[0]-1))/2;
     for(int i=1;i<=k/2;i++){
         if(i==k-i){
             totalpairs+=(remFreq[i]*(remFreq[i]-1))/2;
             
         }
         else{
             totalpairs+=remFreq[i]*remFreq[k-i];
         }
     }
     return totalpairs;
    }
};