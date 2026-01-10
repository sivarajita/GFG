class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        int n = arr.size();
        int max = 0;
        int frq[1000001] = {0};
        for(int i = 0; i < arr.size();i++){
            frq[arr[i]]++;
            if(max < arr[i]){
                max = arr[i];
            }
        }
        vector<int> v;
        for(int i = 0;i <= max;i++){
            if(frq[i] > 1) v.push_back(i);
        }
        return v;
    }
};
