// User function Template for C++

int nthDay(int d, int n) {

    // write your code here
    int a=(d-n)%7;
    if(a<0){
        a+=7;
    }
    return a;
}