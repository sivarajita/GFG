class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int len=arr.size();
        int mis=-1,rep=-1;
        for(int i=0;i<len;i++){
            int curr = abs(arr[i]);
            if(arr[curr-1]>0){
                arr[curr-1]*=-1;
            }
            else{
                rep=curr;
            }
        }
        for (int i=0;i<len;i++){
            if(arr[i]>0){
                mis=i+1;
                break;
            }
        }
        return {rep,mis};
    }
};