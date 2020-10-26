//立っているフラグの数
//int
int popcnt(int x){
    return __builtin_popcount(x);
}

//long long
int popcntll(long long x){
    return __builtin_popcountll(x);
}

//i番目のフラグをチェック
bool bitcheck(long long bit,int i){
    return bit&(1LL<<i);
}

//i番目のフラグを立てる
void biton(long long& bit,int i){
    bit|=(1LL<<i);
}

//i番目のフラグを消す
void bitoff(long long& bit,int i){
    bit&=~(1LL<<i);
}