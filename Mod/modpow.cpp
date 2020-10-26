//繰り返し二乗法
long long modpow(long long x,long long n,int m){
    assert(n>=0);
    assert(m>0);
    long long res=1;
    x=(x%m+m)%m;
    while(n>0){
        if(n&1){
            res=res*x;
            res%=m;
        }
        x=x*x;
        x%=m;
        n>>=1;
    }
    return res;
}