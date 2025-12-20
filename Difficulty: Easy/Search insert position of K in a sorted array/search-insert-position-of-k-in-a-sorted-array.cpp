class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==k)
            return mid;
            else if(arr[mid]<k)
            low=mid+1;
            else
            high=mid-1;
        }
        return low;
    }
};