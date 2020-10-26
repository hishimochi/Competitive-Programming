//Zalgorithm
//sとs[i:|S|-1]の最長共通接頭辞の長さを求める
vector<int> Zalgorithm(const string& s){
    int n=s.size();
    vector<int> prefix(n);
    prefix[0]=n;
    int i=1,j=0;
    while(i<n){
        while(i+j<n&&s[j]==s[i+j])++j;
        prefix[i]=j;
        if(!j){
            i++;
        }else{
            int k=1;
            while(i+k<n&&k+prefix[k]<j)prefix[i+k]=prefix[k],++k;
            i+=k,j-=k;
        }
    }
    return prefix;
}