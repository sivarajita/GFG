// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size()-1;
        int ans=-1;
        for(int i=0;i<n;i++){
            while(m>=0&&arr[i][m]==1){
                ans=i;
                m--;
            }
            if(m==-1)
            return i;
        }
        return ans;
    }
};