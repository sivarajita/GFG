class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int> result;
        int c=0;
        int q=queries.size();
        for(int i=q-1;i>=0;i--){
            int type=queries[i][0];
            int x=queries[i][1];
            if(type==1){
                c^=x;
            }
            else{
                result.push_back(x^c);
            }
        }
        result.push_back(0^c);
        sort(result.begin(),result.end());
        return result;
    }
};
