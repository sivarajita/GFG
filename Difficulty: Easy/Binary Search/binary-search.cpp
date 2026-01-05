class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int left=0;
        int right=arr.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr[mid]==k){
                ans=mid;
                right=mid-1;
            }
            else if(arr[mid]<k){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return ans;
    }
};