class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n=s.length();
        int total_closing=0;
        for(char ch : s){
            if(ch==')'){
            total_closing++;
        }
    }
    int open=0;
    for(int k=0;k<n;k++){
        if(open == total_closing){
            return k;
        }
        if(s[k]=='('){
            open++;
        }
        else if(s[k]==')'){
            total_closing--;
        }
    }
    if(open==total_closing){
        return n;
    }
    return -1;
}
};