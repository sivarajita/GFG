// User function template for C++
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int frq[1000001] = {0};
        for(int i = 0;i <= n-1;i++){
            frq[arr[i]]++;
        }
        //cout << frq[n+1];
        for(int i = 1;i <= n+1;i++){
            if(frq[i] == 0) return i;
        }
        return arr[0];
    }
};
