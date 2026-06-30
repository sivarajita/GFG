class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size();
        int m=b.size();
        std::unordered_map<int,int> b_map;
        for(int i=0;i<m;i++){
            b_map[b[i]]=i;
        }
        std::vector<int> temp;
        for(int i=0;i<n;i++){
            if(b_map.find(a[i])!=b_map.end()){
                temp.push_back(b_map[a[i]]);
                
            }
        }
        std::vector<int> lis;
        for(int num:temp){
            auto it=std::lower_bound(lis.begin(),lis.end(),num);
            if(it==lis.end()){
                lis.push_back(num);
            }
            else{
                *it=num;
            }
        }
        int L = lis.size();
        return n+m-2*L;
    }
};