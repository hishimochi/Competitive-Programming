//素因数分解
map<long long,int> PrimeFactorization(long long n){
    map<long long,int> ret;
    for(long long i=2;i*i<=n;i++){
        while(n%i==0){
            ret[i]++;
            n/=i;
        }
    }
    if(n!=1)ret[n]++;
    return ret;
}