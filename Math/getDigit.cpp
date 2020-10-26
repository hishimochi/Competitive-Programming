//桁数
int getDigit(long long x){
    if(x<0)x*=-1;
    if(x<10)return 1;
    return getDigit(x/10)+1;
}