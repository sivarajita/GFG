class Solution {
  public:
    string chooseSwap(string &s) {
        // code here
        set<char> unique;
        for(char ch:s){
            unique.insert(ch);
        }
        for(int i=0;i<s.length();i++){
            char current=s[i];
            unique.erase(current);
            if(unique.empty()){
                break;
            }
            char smallest=*unique.begin();
            if(smallest<current){
                char char1=current;
                char char2=smallest;
                for(int j=0;j<s.length();j++){
                    if(s[j]==char1){
                        s[j]=char2;
                    }
                    else if(s[j]==char2){
                        s[j]=char1;
                    }
                }
                return s;
            }
        }
        return s;
    }
};
