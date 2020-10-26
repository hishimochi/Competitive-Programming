//約数列挙
vector<long long> divisor(long long n){
    vector<long long> ret;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            ret.emplace_back(i);
            if(i*i!=n)ret.emplace_back(n/i);
        }
    }
    //昇順ソート
    sort(ret.begin(),ret.end());
    return ret;
}