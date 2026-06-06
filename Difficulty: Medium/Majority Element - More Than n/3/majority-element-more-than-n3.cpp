class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int> result;
        int count=1;
        for(int i=1;i<=n;i++){
            if(i<n && arr[i] == arr[i-1]){
                count++;
            }
            else{
                if(count>n/3){
                    result.push_back(arr[i-1]);
                }
                count=1;
            }
    }
        return result;
    }
};