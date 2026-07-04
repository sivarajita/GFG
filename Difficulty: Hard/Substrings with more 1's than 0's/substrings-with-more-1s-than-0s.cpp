class Solution {
    private: 
    void update(vector<int>& bit,int index,int val,int n){
        while(index <= n){
            bit[index] += val;
            index += (index & -index);
        }
    }
    int query(vector<int>& bit,int index){
        int sum=0;
        while (index>0){
            sum+=bit[index];
            index-=(index & -index);
        }
        return sum;
    }
    
  public:
    int countSubstring(string& s) {
        // Code Here
        int n=s.length();
        int max_val = 2*n+1;
        vector<int> bit(max_val+1,0);
        long long ans=0;
        int curr_sum=0;
        update(bit, n+1,1,max_val);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                curr_sum+=1;
            }
            else{
                curr_sum-=1;
            }
            int bit_idx=curr_sum+n+1;
            ans+=query(bit,bit_idx-1);
            update(bit,bit_idx,1,max_val);
        }
        return ans;
        
    }
};