class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        vector<int>even;
        vector<int>odd;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0){
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        reverse(odd.begin(),odd.end());
        for(int i=0;i<odd.size();i++){
            arr[i]=odd[i];
        }
        int size=odd.size();
        for(int i=0;i<even.size();i++){
            arr[size]=even[i];
            size++;
        }
    }
};