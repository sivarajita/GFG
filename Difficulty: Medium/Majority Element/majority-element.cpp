class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
      int c=0;
      int count=0;
      for(int num:arr){
          if(count==0){
              c=num;
              count=1;
          }
          else if(num == c){
              count++;
          }
          else{
              count--;
          }
      }
      for(int num:arr){
          if(num==c){
              count++;
          }
      }
      return (count>arr.size()/2)?c:-1;
       
    }
};