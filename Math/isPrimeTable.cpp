//素数判定表
vector<bool> isPrimeTable(int n){
    vector<bool> prime(n+1,true);
    prime[0]=false;
    prime[1]=false;
    for(long long i=2;i*i<=n;i++){
        if(!prime[i])continue;
        for(long long j=i+i;j<=n;j+=i){
            prime[j]=false;
        }
    }
    return prime;
}