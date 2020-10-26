//vectorの重複要素を消す
template<class T>
void makeunique(vector<T>& v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}