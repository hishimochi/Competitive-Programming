//素数列挙
vector<int> Eratosthenes(int n){
    vector<bool> primedesu(n+1,true);
    vector<int> P;
    for(int i=2;i<=n;i++){
        if(primedesu[i]){
            for(long long j=2*i;j<=n;j+=i){
                primedesu[j]=false;
            }
            P.emplace_back(i);
        }
    }
    return P;
}