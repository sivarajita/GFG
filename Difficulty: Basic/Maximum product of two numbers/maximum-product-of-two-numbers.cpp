// User function template for C++
class Solution {
  public:

    int maxProduct(vector<int>& arr) {
        // code here
        // int n = arr.size();
      int max1=0,max2=0;
      for(int x : arr){
          if(x>max1){
              max2=max1;
              max1=x;
          }
          else if(x>max2){
              max2=x;
          }
      }
      return max1*max2;
    }
};