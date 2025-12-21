int firstDigit(int n) {
    // code here
    int a,b=n;
    while(b!=0){
        a=b%10;
        b/=10;
    }
    return a;
}