//座標圧縮
template <class T>
vector<T> Compress(vector<T> &X){
    vector<T> vals=X;
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(unsigned i=0;i<X.size();i++){
        X[i]=lower_bound(vals.begin(),vals.end(),X[i])-vals.begin();
    }
    //元の値を保持した配列を返す
    return vals;
}