//繰り返し二乗法
template<class T>T pow_(T x,ll n){
    assert(n>=0);
    T res=1;
    while(n>0){
        if(n&1){
            res=res*x;
        }
        x=x*x;
        n>>=1;
    }
    return res;
}