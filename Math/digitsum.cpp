//各桁の和
//数値版
int digitsum(long long x){
    if(x<10)return x;
    return x%10+digitsum(x/10);
}

//文字列版
int digitsum(string s){
    int res=0;
    for(unsigned i=0;i<s.size();i++){
        res+=s[i]-'0';
    }
    return res;
}