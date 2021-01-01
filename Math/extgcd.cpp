//ax+by=gcd(a,b)を満たすx,yを求める
//返り値 gcd(a,b)
//計算量 O(log a)
long long extgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    long long d=extgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}