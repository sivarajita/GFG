class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        if(pos==1){
            return "Engineer";
        }
        string parentprofession = profession(level-1,(pos+1)/2);
        if(pos%2!=0){
            return parentprofession;
        }
        else{
            return (parentprofession == "Engineer") ? "Doctor" : "Engineer";
        }
    }
};